#include "main.h"

/**
 * parser - uses strtok to tokenize a string
 * @input: the input read from getline
 *
 * Return: tokenized arguments
 */

char **parser(char *buff)
{
	char **args;
	char *arg1, *delim = " \n\t";
	int n = BUFFSIZE, i;

	if (buff[0] == ' ' && buff[strlen(buff) - 1] == ' ')
		exit(0);
	if (buff == NULL)
		return (NULL);

	args =malloc(sizeof(char *) * n);
	if (args == NULL)
	{
		free(args);
		perror("Couldn't allocate memory");
		return (NULL);
	}
	arg1 = strtok(buff, delim);
	for (i = 0; arg1; i++)
	{
		args[i] = arg1;
		arg1 = strtok(NULL, delim);
	}
	args [i] = NULL;
	/*free_arr(args);*/
	return (args);
}
