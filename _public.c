#include "_public.h"

int max(const int num1, const int num2)
{
  if(num1 > num2)
    return num1;
  else
    return num2;
}

int min(const int num1, const int num2)
{
  if(num1 > num2)
    return num2;
  else
    return num1;
}

int ctoi(const char chr)
{
    if(chr >= '0' && chr <= '9')
        return chr - '0';
    else
        return -1;
}

int ATOI(const char *nptr)
{
  int result = 0;
  int flag = 1;

  switch(*nptr)
  {
    case '+': flag = 1; nptr++; break;
    case '-': flag = 0; nptr++; break;
  }

  while(*nptr != 0)
  {
    if(*nptr >= '0' && *nptr <= '9')
    {
      result = result * 10 + ctoi(*nptr);
      nptr++;
    }
    else
    {
      nptr++;
    }
  }

  if(flag == 0) result = -result;

  return result;
}

long ATOL(const char *nptr)
{
  long result = 0;
  int flag = 1;

  switch(*nptr)
  {
    case '+': flag = 1; nptr++; break;
    case '-': flag = 0; nptr++; break;
  }

  while(*nptr != 0)
  {
    if(*nptr >= '0' && *nptr <= '9')
    {
      result = result * 10 + ctoi(*nptr);
      nptr++;
    }
    else
    {
      nptr++;
    }
  }

  if(flag == 0) result = -result;

  return result;
}

char *STRCPY(char* dest,const size_t destsize,const char* src)
{
    size_t len = 0;
    while(len < destsize)
    {
        dest[len] = src[len];
        len++;
        if(src[len] == 0) break;
    }
    if(len == destsize)
        dest[len - 1] = 0;
    else
        dest[len] = 0;

    return dest;
}

char *STRNCPY(char* dest,const size_t destsize,const char* src,size_t n);
char *STRCAT(char* dest,const size_t destsize,const char* src);
char *STRNCAT(char* dest,const size_t destsize,const char* src,size_t n);
