#include "monty.h"

/**
* strCat - Concatinates two strings with manual allocation.
* @str1: first string.
* @str2: second string.
* Return: pointer to the newly created string
**/
void freeArr(char **arrs)
{
int i;
int len = globaldata->linecount;
for (i = 0; i < len; i++) {
  free(arrs[i]);
}
free(arrs);
arrs = NULL;
}
