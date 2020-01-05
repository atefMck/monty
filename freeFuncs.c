#include "monty.h"

/**
* freeArr - frees an array of chars.
* @arrs: the array to be freed.
* Return: void
**/
void freeArr(char **arrs)
{
int i;
int len = globaldata->linecount;
for (i = 0; i < len; i++)
free(arrs[i]);
free(arrs);
arrs = NULL;
}
