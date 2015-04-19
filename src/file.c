#include <stdio.h>
#include <stdlib.h>
#include "file.h"

fdata_t * file_open(char * fname)
{
	fdata_t * d;
	FILE * f;

	d = malloc(sizeof(fdata_t));	

	f = fopen(fname, "r");

	fseek(f, 0, SEEK_END);
	d->size = ftell(f);
	rewind(f);

	d->data = malloc(d->size);
	fread(d->data, 1, d->size, f);

	fclose(f);	

	return d;
}

int file_write(fdata_t * d)
{

	return 0;
}

void file_free(fdata_t * d)
{
	free(d->name);
	free(d->data);
	free(d);
}
