#include "monty.h"

/**
* debugMem - verifies memory allocation of string
* @str: the string to debug
* Return: void
**/
void debugMem(char *str)
{
if (str == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
}

/**
* debugMemArr - verifies memory allocation of string
* @str: the array of string to debug
* Return: void
**/
void debugMemArr(char **str)
{
if (str == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
}

/**
* debugMemStack - verifies memory allocation of stack
* @stack: the array of string to debug
* Return: void
**/
void debugMemStack(stack_t *stack)
{
if (stack == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
}

/**
* debugFile - verifies memory allocation of file
* @fptr: the file to debug
* @path: path of file
* Return: void
**/
void debugFile(FILE *fptr, const char *path)
{
if (!fptr)
{
fprintf(stderr, "Error: Can't open file <%s>\n", path);
exit(EXIT_FAILURE);
}
}
