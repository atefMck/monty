#ifndef MONTY_HEADER
#define MONTY_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct gdata_s - global variables
* @filepath: the opcode
* @fileadress: function to handle the opcode
* @number: the data to add
* @linecount: currently active line
* @top: top list in stack
* @head: rear list in stack
* Description: some global variables needed
*/
typedef struct gdata_s
{
char *filepath;
FILE *fileadress;
char *number;
size_t linecount;
stack_t *top;
stack_t *head;
int v;
} gdata_t;

extern gdata_t *globaldata;

char **fileHandle(const char *path);
char **fixSpace(char **arrs);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

char *strCat(const char *str1, const char *str2);
char *strCatNoS(const char *str1, const char *str2);
int strLen(const char *str);
int strLenNoS(const char *str);

void freeArr(char **arrs);
void freeGlobal();
void freeStack();

void debugMem(char *str);
void debugFile(FILE *fptr, const char *str);
void debugMemArr(char **str);
void debugMemStack(stack_t *stack);

#endif
