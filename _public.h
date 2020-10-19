#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 返回两个数字的最大值
int max(const int num1, const int num2);

// 返回两个数字的最大值
int min(const int num1, const int num2);

// 用于把数字的字符转换为整数，chr为用字符方式表示的数字，函数的返回值为数字的整数。
// 如果chr不是数字的字符，函数返回-1。
int ctoi(const char chr);

// 将数字字符串转换为int类型的整型数字
// 并且在碰到非数字字符会直接跳过，不会结束转换
int ATOI(const char *nptr);

// 将数字字符串转换为long类型的整形数字
// 并且在碰到非数字字符会直接跳过，不会结束转换
long ATOL(const char *nptr);

// 安全的strcpy函数。
// dest：目标字符串，不需要初始化，在STRCPY函数中会对它进行初始化。
// destlen：目标字符串dest占用内存的大小。
// src：原字符串。
// 返回值：目标字符串dest的地址。
char *STRCPY(char* dest,const size_t destlen,const char* src);

// 安全的strncpy函数。
// dest：目标字符串，不需要初始化，在STRNCPY函数中会对它进行初始化。
// destlen：目标字符串dest占用内存的大小。
// src：原字符串。
// n：待复制的字节数。
// 返回值：目标字符串dest的地址。
char *STRNCPY(char* dest,const size_t destlen,const char* src,size_t n);

// 安全的strcat函数。
// dest：目标字符串。
// destlen：目标字符串dest占用内存的大小。
// src：待追加的字符串。
// 返回值：目标字符串dest的地址。
char *STRCAT(char* dest,const size_t destlen,const char* src);

// 安全的strncat函数。
// dest：目标字符串。
// destlen：目标字符串dest占用内存的大小。
// src：待追加的字符串。
// n：待追加的字节数。
// 返回值：目标字符串dest的地址。
char *STRNCAT(char* dest,const size_t destlen,const char* src,size_t n);

// 删除字符串左边指定的字符。
// str：待处理的字符串。
// chr：需要删除的字符。
void DeleteLChar(char *str,const char chr);

// 删除字符串右边指定的字符。
// str：待处理的字符串。
// chr：需要删除的字符。
void DeleteRChar(char *str,const char chr);

// 删除字符串左右两边指定的字符。
// str：待处理的字符串。
// chr：需要删除的字符。
void DeleteLRChar(char *str,const char chr);

// 把字符串中的小写字母转换成大写，忽略不是字母的字符。
// str：待转换的字符串，支持char[]和string两种类型。
void ToUpper(char *str);

// 把字符串中的大写字母转换成小写，忽略不是字母的字符。
// str：待转换的字符串，支持char[]和string两种类型。
void ToLower(char *str);

// 解析XML字符串的函数族，支持int、char *和double三种类型。
// 返回值：0-成功，-1-失败。
// in_XMLBuffer，XML格式的字符串
// in_FieldName，字段的标签名
// out_Value，获取内容存放的变量的指针
int GetXMLBuffer_Int(const char *in_XMLBuffer,const char *in_FieldName,int *out_Value);
int GetXMLBuffer_Str(const char *in_XMLBuffer,const char *in_FieldName,char *out_Value);
int GetXMLBuffer_Double(const char *in_XMLBuffer,const char *in_FieldName,double *out_Value);
