// 这是一个学习C语言文件操作的测试程序
// 1）编写示例程序，从界面上输入五名超女的数据，存放在struct st_girl结构体数组中，然后把结构体数组以二进制的方式写入文件。
// 2）编写示例程序，把上一题写入的数据从二进制文件中读取出来，存入struct st_girl结构体中，然后在界面上显示出来。
// 3）编写示例程序，从界面上输入五名超女的数据，存放在struct st_girl结构体数组中，然后把结构体数组以xml字符串的方式写入文本文件。
// 4）编写示例程序，把上一题写入的数据从文本文件中读取出来，并解析xml，存入struct st_girl结构体中，然后在界面上显示出来。

#include <stdio.h>
#include <string.h>
#include "../_public.h"

struct st_girl{
    char name[50];
    int age;
    int height;
    char sc[30];
    char yz[30];
};

int main()
{
    FILE *fp;
    char strBuffer[1024];
    struct st_girl girl[5];
    struct st_girl girl2[5];

    if ( (fp = fopen("./girl.bat","wb")) == 0)
    {
        printf("open file failed.");
        return -1;
    }
    memset(strBuffer, 0, sizeof(strBuffer));
    memset(girl, 0, sizeof(girl));
    memset(girl2, 0, sizeof(struct st_girl));

    // 题1
    printf("请输入信息：（姓名 年龄 身高 身材 颜值）\n");
    for(int i = 0; i < 5; i++){
        scanf("%s%d%d%s%s",girl[i].name,&girl[i].age,&girl[i].height,girl[i].sc,girl[i].yz);
        fwrite(&girl[i],1,sizeof(girl[i]),fp);
    }
    fclose(fp);

    // 题2
    if ( (fp = fopen("./girl.bat","rb")) == 0)
    {
        printf("open file failed.");
        return -1;
    }
    for(int i = 0; i < 5; i++){
        fread(&girl2[i],1,sizeof(girl2[i]),fp);
        printf("name=%s,age=%d,height=%d,sc=%s,yz=%s\n",\
                         girl2[i].name,girl2[i].age,girl2[i].height,girl2[i].sc,girl2[i].yz);
    }
    fclose(fp);

    // 题3
    if ( (fp = fopen("./girl.xml","a")) == 0)
    {
        printf("open file failed.");
        return -1;
    }
    for(int i = 0; i < 5; i++){
        fprintf(fp,"<name>%s</name><age>%d</age><height>%d</height><sc>%s</sc><yz>%s</yz>\n",girl[i].name,girl[i].age,girl[i].height,girl[i].sc,girl[i].yz);
    }
    fclose(fp);

    // 题4
    if ( (fp = fopen("./girl.xml","r")) == 0)
    {
        printf("open file failed.");
        return -1;
    }
    
    while(1){
        int i = 0;
        if((fgets(strBuffer,10,fp) == 0)) break;
        GetXMLBuffer_Str(strBuffer,"name",girl2[i].name);
        GetXMLBuffer_Int(strBuffer,"age",&girl2[i].age);
        GetXMLBuffer_Int(strBuffer,"height",&girl2[i].height);
        GetXMLBuffer_Str(strBuffer,"sc",girl2[i].sc);
        GetXMLBuffer_Str(strBuffer,"yz",girl2[i].yz);
        i++;
    }

    for(int i = 0; i < 5; i++){
        printf("name=%s,age=%d,height=%d,sc=%s,yz=%s\n",\
                         girl2[i].name,girl2[i].age,girl2[i].height,girl2[i].sc,girl2[i].yz);

    }
    fclose(fp);
    
    return 0;
}

