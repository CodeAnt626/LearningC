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

char *STRCPY(char* dest,const size_t destlen,const char* src)
{
  if (dest==0) return 0;
  memset(dest,0,destlen);   // 初始化dest。
  if (src==0) return dest;

  if (strlen(src)>destlen-1) strncpy(dest,src,destlen-1); 
  else strcpy(dest,src);

  return dest;
}

char *STRNCPY(char* dest,const size_t destlen,const char* src,size_t n)
{
  if (dest==0) return 0;
  memset(dest,0,destlen);   // 初始化dest。
  if (src==0) return dest;

  if (n>destlen-1) strncpy(dest,src,destlen-1); 
  else strncpy(dest,src,n);

  return dest;
}

char *STRCAT(char* dest,const size_t destlen,const char* src)
{
  if (dest==0) return 0;
  if (src==0) return dest;

  unsigned int left=destlen-1-strlen(dest);

  if (strlen(src)>left) { strncat(dest,src,left); dest[destlen-1]=0; }
  else strcat(dest,src);

  return dest;
}

char *STRNCAT(char* dest,const size_t destlen,const char* src,size_t n)
{
  if (dest==0) return 0;
  if (src==0) return dest;

  size_t left=destlen-1-strlen(dest);

  if (n>left) { strncat(dest,src,left); dest[destlen-1]=0; }
  else strncat(dest,src,n);

  return dest;
}

void DeleteLChar(char *str,const char chr)
{
  if (str == 0) return;
  if (strlen(str) == 0) return;

  char strTemp[strlen(str)+1];

  int iTemp=0;

  memset(strTemp,0,sizeof(strTemp));
  strcpy(strTemp,str);

  while ( strTemp[iTemp] == chr )  iTemp++;

  memset(str,0,strlen(str)+1);

  strcpy(str,strTemp+iTemp);

  return;
}

void DeleteRChar(char *str,const char chr)
{
  if (str == 0) return;
  if (strlen(str) == 0) return;

  int istrlen = strlen(str);

  while (istrlen>0)
  {
    if (str[istrlen-1] != chr) break;

    str[istrlen-1]=0;

    istrlen--;
  }
}

void DeleteLRChar(char *str,const char chr)
{
  DeleteLChar(str,chr);
  DeleteRChar(str,chr);
}

void ToUpper(char *str)
{
  if (str == 0) return;

  if (strlen(str) == 0) return;

  int istrlen=strlen(str);

  for (int ii=0;ii<istrlen;ii++)
  {
    if ( (str[ii] >= 'a') && (str[ii] <= 'z') ) str[ii]=str[ii] - 32;
  }
}

void ToLower(char *str)
{
  if (str == 0) return;

  if (strlen(str) == 0) return;

  int istrlen=strlen(str);

  for (int ii=0;ii<istrlen;ii++)
  {
    if ( (str[ii] >= 'A') && (str[ii] <= 'Z') ) str[ii]=str[ii] + 32;
  }
}
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
