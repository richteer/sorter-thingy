#ifndef _file_h_
#define _file_h_

typedef struct {
	char * name;
	char * data;
	size_t size;
} fdata_t;

fdata_t * file_open(char * fname);
int file_write(fdata_t * d);
void file_free(fdata_t * d);

#endif
