#include <stdio.h>
#include <string.h>
#include "headers.h"
#define MAXLEN 1000

int readlines(char *lineptr[], int maxlines, char lines[], int size)
{
	int len, nlines;
	char *p, line[MAXLEN];
	
	p = lines;
	
	nlines = 0;
	while ((len = _getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (line + size - p) < len)
			return -1;
	else
	{
		line[len-1] = '\0';
		strcpy(p, line);
		lineptr[nlines++] = p;
		p += len;
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

int _getline(char s[], int lim)
{
	int c, i;
	
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}


