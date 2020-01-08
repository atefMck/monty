#include "monty.h"

/**
* swap - swaps the two first int in stack
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
