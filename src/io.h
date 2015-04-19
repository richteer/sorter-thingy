#ifndef _io_h_
#define _io_h_

typedef struct node_s {
	struct node_s * next;
	char * filename;
} node_t;

typedef struct list_s {
	node_t * head;
	node_t * tail;
} list_t;



list_t * io_load(char * dirname);
node_t * io_next(list_t * ls);
void io_free(node_t * n);



#endif
