#include "monty.h"

gdata_t *globaldata;

/**
* main - main function for monty language interpreter
* @argc: arguments count
* @argv: value of arguments
* Return: exit status.
*/

int main(int argc, char const *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
stack_t *stack = NULL;
size_t i = 0, j = 1;
char *token, *aux, **instrucs;
gdata_t init = {"", NULL, "", 0, NULL, NULL};
instruction_t opcodes[] = {
{"push", push},
{"pall", pall},
{NULL, NULL}
};
globaldata = &init;
globaldata->filepath = strCat(globaldata->filepath, argv[1]);
instrucs = fixSpace(fileHandle(globaldata->filepath));
globaldata->top = stack;
for (j = 0; j < globaldata->linecount; j++)
{
aux = strCat("", instrucs[j]);
token = strtok(aux, " ");
if (strcmp(token, "push") == 0)
{
token = strtok(NULL, " ");
globaldata->number = strCat("", token);
}
i = 0;
while (opcodes[i].opcode)
{
if (strcmp(opcodes[i].opcode, aux) == 0)
{
opcodes[i].f(&globaldata->top, j);
break;
}
i++;
}
free(aux);
}
}
