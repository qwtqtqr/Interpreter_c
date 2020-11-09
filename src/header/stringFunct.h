#ifndef STR_FUNC
#define  STR_FUNC
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int indexOf(char* mainStr, char* str, int fromIndex)
{
	char* mainString = &mainStr[fromIndex];
	char* found = strstr(mainString, str);
	if (found != NULL)
	{
		return (int)(found - mainStr);
	}
	return -1;
}


static char* subString(char* string, int start, int end)
{
	int length = end - start;
	if (length < 0)
	{
		printf("Error: 'end' value is smaller than 'start' value.\n");
		exit(1);
	}
	char* pointer;
	int c;

	pointer = malloc(length + 1);

	if (pointer == NULL)
	{
		printf("Error: Unable to allocate memory.\n");
		exit(1);
	}

	for (c = 0; c < length; c++)
	{
		*(pointer + c) = *(string + start - 1);
		string++;
	}

	*(pointer + c) = '\0';

	return pointer;
}



static unsigned int str_getSize(const char* str_)
{
	int i = 0;
	while (*(str_ + i) != '\0')
	{
		i++;
	}
	return i;
}



static char* str_trim(const char* str_in)
{
	char* str_2 = str_in;
	unsigned int count = 0;
	while (*(str_in + count) == ' ')
	{
		str_2++;
		count++;
	}
	unsigned int strSize = str_getSize(str_2);
	unsigned int i = strSize;
	while (*(str_2 + i - 1) == ' ')
	{
		i--;
	}
	if (i == strSize)
	{
		return str_2;
	}
	char* out = calloc(i, sizeof(char));
	for (int c = 0; c < i; c++)
	{
		out[c] = *(str_2 + c);
	}
	out[i] = '\0';
	return out;
}

#endif