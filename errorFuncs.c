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
