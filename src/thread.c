#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "io.h"


typedef struct {
	sem_t * sem;
	list_t * ls;
	char * odir;
} targs_t;


static void thread_do(targs_t * args)
{	
	node_t * n;

	while (1) {
		sem_wait(args->sem);
		n = io_next(args->ls);
		sem_post(args->sem);

		if (!n) {
			break; // No files left.
		}

		// Do the sort

	}

	return;
}


int thread_main(char * idir, char * odir, int thrs)
{
	int i;
	sem_t sem;
	targs_t args;
	pthread_t * threads = malloc(sizeof(pthread_t) * thrs);

	sem_init(&sem, 0, 1);
	args.sem = &sem;
	args.ls = io_load(idir);
	args.odir = odir;

	for (i = 0; i < thrs; i++) {
		pthread_create(&threads[i], NULL, (void*(*)(void*))thread_do, (void*) &args);
	}

	for (i = 0; i < thrs; i++) {
		pthread_join(threads[i], NULL);
	}

	free(threads);

	return 0;
}
