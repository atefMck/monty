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
if (*arrs == NULL)
return;
for (i = 0; i < len; i++)
free(arrs[i]);
free(arrs);
arrs = NULL;
}

/**
* freeArr - frees all global data.
* Return: void
**/
void freeGlobal()
{
if (strcmp(globaldata->filepath, "") != 0)
free(globaldata->filepath);
if (strcmp(globaldata->number, "") != 0)
free(globaldata->number);
}

/**
* freeStack - frees the stack.
* Return: void
**/
void freeStack()
{
stack_t *stack;
if (!globaldata->top)
return;
while (globaldata->top) {
stack = globaldata->top;
globaldata->top = globaldata->top->prev;
free(stack);
}
}
