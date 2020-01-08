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
stack_t *stack = NULL;
size_t i = 0, j = 0;
char *token, *aux, *code, **instrucs;
gdata_t init = {"", NULL, "", 0, NULL, NULL, 1};
instruction_t opcodes[] = { {"push", push}, {"pall", pall}, {"pint", pint},
 {"pop", pop}, {"swap", swap}, {"nop", nop}, {"sub", sub}, {"add", add},
 {"div", _div}, {"mul", mul}, {"mod", mod}, {NULL, NULL}
};
debugUsage(argc);
globaldata = &init;
globaldata->filepath = strCat(globaldata->filepath, argv[1]);
instrucs = fixSpace(fileHandle(globaldata->filepath));
globaldata->top = stack;
for (j = 0; j < globaldata->linecount; j++)
{
aux = strCat("", instrucs[j]);
code = aux;
token = strtok(code, " ");
if (!token)
goto skip;
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
opcodes[i].f(&globaldata->top, j + 1);
}
i++;
}
skip:
free(aux);
}
freeArr(instrucs);
freeStack();
freeGlobal();
return (0);
}
