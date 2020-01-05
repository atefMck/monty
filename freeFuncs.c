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

/**
* freeArr - frees all global data.
* Return: void
**/
void freeGlobal()
{
free(globaldata->filepath);
free(globaldata->number);
}

/**
* freeStack - frees the stack.
* Return: void
**/
void freeStack()
{
stack_t *stack;
while (globaldata->top) {
stack = globaldata->top;
globaldata->top = globaldata->top->prev;
free(stack);
}
}
