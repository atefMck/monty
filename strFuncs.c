#include "header.h"

/**
* strCat - Concatinates two strings with manual allocation.
* @str1: first string.
* @str2: second string.
* Return: pointer to the newly created string
**/
char **fixSpace(char **arrs)
{
char **arrnos;
arrnos = malloc(sizeof(char *) * globaldata->linecount);
if (!arrnos) {
  fprintf(stderr, "Error: malloc failed\n");
  exit(EXIT_FAILURE);
}

int i;
int len = globaldata->linecount;
for (i = 0; i < len; i++)
{
  arrnos[i] = strCatNoS("", arrs[i]);
}
freeArr(arrs);
return(arrnos);
}


/**
* strCat - Concatinates two strings with manual allocation.
* @str1: first string.
* @str2: second string.
* Return: pointer to the newly created string
**/
char *strCatNoS(const char *str1, const char *str2)
{
  size_t s1, s2, s3, i = 0;
  char *a;
  s1 = strLenNoS(str1);
  s2 = strLenNoS(str2);
  s3 = s1 + s2 + 1;
  a = malloc(s3);
  if (a == NULL)
  {
  fprintf(stderr, "Error: malloc failed\n");
  exit(EXIT_FAILURE);
  }
  while (*str1 != '\0')
  {
  if (*str1 != ' ') {
    a[i] = *str1;
    i++;
  }
  else if (*str1 == ' ' && *(str1 - 1) != ' ' && *(str1 -1) != '\0') {
    a[i] = *str1;
    i++;
  }
  str1++;
  }
  while (*str2 != '\0')
  {
  if (*str2 != ' ') {
    a[i] = *str2;
    i++;
  }
  else if (*str2 == ' ' && *(str2 - 1) != ' ' && *(str2 -1) != '\0') {
    a[i] = *str2;
    i++;
  }
  str2++;
  }
  a[i] = '\0';
  return (a);
}

/**
* strCat - Concatinates two strings with manual allocation.
* @str1: first string.
* @str2: second string.
* Return: pointer to the newly created string
**/
char *strCat(const char *str1, const char *str2)
{
size_t s1, s2, s3, i = 0;
char *a;
s1 = strLen(str1);
s2 = strLen(str2);
s3 = s1 + s2 + 1;
a = malloc(s3);
if (a == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
while (*str1 != '\0')
{
a[i] = *str1;
str1++;
i++;
}
while (*str2 != '\0')
{
a[i] = *str2;
str2++;
i++;
}
a[i] = '\0';
return (a);
}

/**
* strLen - returns length of string.
* @str: string.
* Return: length of a string.
**/
int strLenNoS(const char *str)
{
int i = 0;
int len = 0;
if (!str) {
return (len);
}
while (str[i]){
if (str[i] != ' ')
len++;
else if (str[i] == ' ' && str[i - 1] != ' ' && str[i - 1] != '\0')
len++;
i++;
}
return (len);
}

/**
* strLen - returns length of string.
* @str: string.
* Return: length of a string.
**/
int strLen(const char *str)
{
int len = 0;
if (!str) {
return (len);
}
while (str[len])
len++;
return (len);
}
