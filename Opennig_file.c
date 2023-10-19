#include "monty.h"

/**
 * Opennig_file - the function name
 * @arr: the input
 * Return: the result
 */
FILE *Opennig_file(char *arr)
{
	FILE *file;

	file = fopen(arr, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arr);
		exit(EXIT_FAILURE);
	}
	return (file);
}
