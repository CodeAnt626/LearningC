#include <stdio.h>

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

char *STRCPY(char* dest,const size_t destsize,const char* src);
char *STRNCPY(char* dest,const size_t destsize,const char* src,size_t n);
char *STRCAT(char* dest,const size_t destsize,const char* src);
char *STRNCAT(char* dest,const size_t destsize,const char* src,size_t n);
