#include <stdio.h>
#include <string.h>
#include "_public.h"

struct st_girl
{
    char name[51];   // 姓名
    int  age;        // 年龄
    int  height;     // 身高，单位：cm
    double weight;     // 体重，单位：kg
    char sc[31];     // 身材，火辣；普通；飞机场
    char yz[31];     // 颜值，漂亮；一般；歪瓜裂枣

};

// 解析XML字符串的函数族，支持int、char *和double三种类型。
// 返回值：0-成功，-1-失败。
// in_XMLBuffer，XML格式的字符串
// in_FieldName，字段的标签名
// out_Value，获取内容存放的变量的指针
//int GetXMLBuffer_Int(const char *in_XMLBuffer,const char *in_FieldName,int *out_Value);
//int GetXMLBuffer_Str(const char *in_XMLBuffer,const char *in_FieldName,char *out_Value);
//int GetXMLBuffer_Double(const char *in_XMLBuffer,const char *in_FieldName,double *out_Value);

int main()
{
    struct st_girl girl;
    char strXMLBuffer[1024];

    memset(strXMLBuffer, 0, sizeof(strXMLBuffer));
    memset(&girl, 0, sizeof(girl));

    strcpy(girl.name, "西施");
    girl.age = 18;
    girl.height = 168;
    girl.weight = 48.5;
    strcpy(girl.sc, "火辣");
    strcpy(girl.yz, "漂亮");


    sprintf(strXMLBuffer,
            "<name>%s</name><age>%d</age><height>%d</height><weight>%.1lf</weight><sc>%s</sc><yz>%s</yz>"
            ,girl.name, girl.age, girl.height, girl.weight, girl.sc, girl.yz);

    char name[51];  memset(name,0,sizeof(name));
    int  age=0;
    double weight=0;

    GetXMLBuffer_Str(strXMLBuffer,"name",name); // name的内容将是"西施"
    GetXMLBuffer_Int(strXMLBuffer,"age",&age); // age的内容将是18
    GetXMLBuffer_Double(strXMLBuffer,"sc",&weight); // weight的内容将是48.5
    printf("name=%s,age=%d,\nheight=%d,weight=%0.1lf,\nsc=%s,yz=%s",girl.name,girl.age,girl.height,girl.weight,girl.sc,girl.yz);
    return 0;
}
/*
int GetXMLBuffer_Int(const char *in_XMLBuffer,const char *in_FieldName,int *out_Value)
{
    char strvalue[51];
    memset(strvalue, 0, sizeof(strvalue));
    if(GetXMLBuffer_Str(in_XMLBuffer,in_FieldName,strvalue) != 0) return -1;
    *out_Value = atoi(strvalue);
    return 0;
}

int GetXMLBuffer_Str(const char *in_XMLBuffer,const char *in_FieldName,char *out_Value)
{
    if(out_Value == NULL) return -1;

    char *star = 0;                         // 第一次出现标签字符串的位置
    char *end = 0;                          // 最后一次出现标签字符串的位置

    int nameLen = strlen(in_FieldName);     // 被查找字段的标签的长度
    int valueLen;                           // 被查找字段的长度

    star = strstr(in_XMLBuffer,in_FieldName);

    if(star != 0){
        end = strstr(star + 1, in_FieldName);
    }

    if(star == 0 || end == 0) return -1;

    valueLen = end - star - nameLen - 3;

    strncpy(out_Value, star + nameLen + 3, valueLen);

    out_Value[valueLen] = 0;

    return 0;
    
}

int GetXMLBuffer_Double(const char *in_XMLBuffer,const char *in_FieldName,double *out_Value)
{
    char strvalue[51];
    memset(strvalue, 0, sizeof(strvalue));
    if(GetXMLBuffer_Str(in_XMLBuffer,in_FieldName,strvalue) != 0) return -1;
    *out_Value = atof(strvalue);
    return 0;
}
*/
