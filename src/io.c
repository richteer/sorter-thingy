#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

static int io_append(list_t * ls, char * name)
{
	if (ls->tail == NULL) {
		ls->head = ls->tail = calloc(1,sizeof(node_t));
	}
	else {
		ls->tail->next = calloc(1,sizeof(node)_t);
		ls->tail->next->prev = ls->tail;
		ls->tail = ls->tail->next;
	}

	strcpy(ls->tail->filename = calloc(1,strlen(name)), name);

	return 0;
}


list_t * io_load(char * dirname)
{
	list_t * ls;
	DIR * dirp;
	struct dirent d;

	ls = calloc(1, sizeof(list_t));

	dirp = opendir(dirname);
	if (dirp == NULL) {
		fprintf(stderr, "Failed to open directory '%s'\n",dirname);
		return NULL;
	}

	while (d = readdir(dirp)) {
		io_append(ls, d->filename);
	}

	closedir(dirp);

	return ls;
}


node_t * io_next(list_t * ls)
{
	node_t * tmp;

	tmp = ls->head;

	if (!tmp) {
		ls->head = ls->head->next;
	}

	return tmp;
}

