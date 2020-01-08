#include "monty.h"

/**
* mul - multiplite the top two elements of the stack
* @top: the top of the stack
* @line_number: value of arguments
* Return: exit status.
*/

void mul(SP stack_t **top, SP unsigned int line_number)
{
stack_t *po;
if (!globaldata->top)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
if (globaldata->top->prev == NULL && globaldata->top == NULL)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
po = globaldata->top;
globaldata->top->prev->n *= globaldata->top->n;
globaldata->top = globaldata->top->prev;
globaldata->top->next = NULL;
free(po);

}




/**
* add - adds the top two elements of the stack
* @top: the top of the stack
* @line_number: value of arguments
* Return: exit status.
*/

void add(SP stack_t **top, SP unsigned int line_number)
{
stack_t *po;
if (!globaldata->top)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
if (globaldata->top->prev == NULL && globaldata->top == NULL)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
po = globaldata->top;
globaldata->top->prev->n += globaldata->top->n;
globaldata->top = globaldata->top->prev;
globaldata->top->next = NULL;
free(po);

}


/**
* pall - prints all stack
* @top: the top of the stack
* @line_number: value of arguments
* Return: exit status.
*/
void pall(stack_t **top, unsigned int line_number)
{
stack_t *newStack;
(void) line_number;
if (*top == NULL)
return;
newStack = (*top);
while (newStack)
{
printf("%d\n", newStack->n);
newStack = newStack->prev;
}
}






/**
* pint - prints stack on top
* @top: the top of the stack
* @line_number: value of arguments
* Return: exit status.
*/
void pint(SP stack_t **top, SP unsigned int line_number)
{
if (!globaldata->top)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", globaldata->top->n);
}

/**
* pop - pops an int from stack
* @top: the top of the stack
* @line_number: line count
* Return: exit status.
*/
void pop(SP stack_t **top, SP unsigned int line_number)
{
stack_t *po;
if (!globaldata->top)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
po = globaldata->top;
globaldata->top = globaldata->top->prev;
globaldata->top->next = NULL;
free(po);

}
