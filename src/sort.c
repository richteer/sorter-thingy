#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


static int sort_compare(const void * a, const void * b)
{
	char ** as = (char **) a;
	char ** bs = (char **) b;
	int i = 0;

	while (1) {
		if ((*as)[i] - (*bs)[i]) return ((*as)[i] - (*bs)[i]);
		else if ((*as)[i] == '\0') return 0;
		i++;
	}

	return 0; //lolno
}


static int sort_split(fdata_t * d, char *** buffer, size_t * size)
{
	int i,j;
	char * c;
	*size = 0;

	for (i = 0; i < d->size; i++) {
		if (d->data[i] == '\n') {
			d->data[i] = '\0';
			(*size)++;
		}
	}

	*buffer = malloc(sizeof(char**)* (*size));
	c = d->data;
	j = 0;
	for (i = 0; i < d->size; i++) {
		if (d->data[i] == '\0') {
			(*buffer)[j] = c;
			c = (d->data)+i+1;
			j++;
		}
	}	

	return 0;
}

static int sort_join(fdata_t * d, char ** buffer, size_t size)
{
	int i,j;
	char * c;
	char * temp; 

	temp = malloc(d->size);

	j = 0;
	for (i = 0; i < size; i++) {
		for (c = buffer[i]; *c != '\0'; c++) {
			temp[j++] = *c;
		}
		temp[j++] = '\n';
	}
	free(d->data);
	d->data = temp;
	free(buffer);

	return 0;
}

int sort_do(fdata_t * d)
{
	char ** buffer;
	size_t size;

	sort_split(d, &buffer, &size);
	qsort(buffer, size, sizeof(char*), sort_compare);
	sort_join(d, buffer, size);

	return 0;
}
