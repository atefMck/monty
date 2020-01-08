#include "monty.h"

/**
* strConv - converts str to int
* @a: the string to conver.
* Return: int
**/
int strConv(char *a)
{
int c, sign, offset, n;
if (a[0] == '-')
sign = -1;
if (sign == -1)
offset = 1;
else
offset = 0;
n = 0;
for (c = offset; a[c] != '\0'; c++)
{
if (a[c] < '0' || a[c] > '9')
return (0);
n = n * 10 + a[c] - '0';
}
if (sign == -1)
n = -n;
return (n);
}
