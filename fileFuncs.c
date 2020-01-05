#include "monty.h"

/**
* fileHandle - handles Monty file
* @path: path of file
* Return: the file lines in an array
*/
char **fileHandle(const char *path)
{
globaldata->fileadress = fopen(path, "r");
if (!globaldata->fileadress)
{
fprintf(stderr, "Error: Can't open file <%s>\n", globaldata->filepath);
exit(EXIT_FAILURE);
}
char *linestr = NULL, *token, **instruct;
size_t linestrsize = 0;
int linesize;
globaldata->linecount = 0;
linesize = getline(&linestr, &linestrsize, globaldata->fileadress);
while (linesize >= 0)
{
globaldata->linecount++;
linesize = getline(&linestr, &linestrsize, globaldata->fileadress);
}
instruct = malloc(sizeof(char *) * globaldata->linecount);
if (!instruct)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
rewind(globaldata->fileadress);
linesize = getline(&linestr, &linestrsize, globaldata->fileadress);
token = strtok(linestr, "\n");
globaldata->linecount = 0;
while (linesize >= 0)
{
instruct[globaldata->linecount] = malloc(sizeof(char) * linesize - 1);
debugMem(instruct[globaldata->linecount]);
strcpy(instruct[globaldata->linecount], token);
globaldata->linecount++;
linesize = getline(&linestr, &linestrsize, globaldata->fileadress);
token = strtok(linestr, "\n");
}
free(linestr);
linestr = NULL;
fclose(globaldata->fileadress);
return (instruct);
}
