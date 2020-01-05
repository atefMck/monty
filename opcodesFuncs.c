#include "monty.h"

/**
* push - pushes into the stack at the top
* @top: the top of the stack
* @line_number: value of arguments
* Return: exit status.
*/
void push(stack_t **top, unsigned int line_number)
{
stack_t *newStack;
int number;
(void) line_number;
newStack = malloc(sizeof(stack_t));
debugMemStack(newStack);
if (globaldata->number[0] == '0')
number = 0;
else if (atoi(globaldata->number) == 0)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
else
number = atoi(globaldata->number);
newStack->n = number;
if (*top == NULL)
{
newStack->prev = NULL;
newStack->next = NULL;
*top = newStack;
}
else
{
(*top)->next = newStack;
newStack->prev = (*top);
newStack->next = NULL;
*top = newStack;
}
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
* pint - prints stack on top
* @top: the top of the stack
* @line_number: value of arguments
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

/**
* pint - prints stack on top
* @top: the top of the stack
* @line_number: value of arguments
* Return: exit status.
*/
void swap(SP stack_t **top, SP unsigned int line_number)
{
int aux;
if (!globaldata->top && !globaldata->top->prev)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
aux = globaldata->top->n;
globaldata->top->n = globaldata->top->prev->n;
globaldata->top->prev->n = aux;
}
