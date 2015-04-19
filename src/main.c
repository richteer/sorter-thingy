#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "thread.h"

typedef struct {
	char * idir;
	char * odir;
	int thrs;
} args_t;


static int parse_args(args_t * args, int argc, char ** argv)
{
	int i;
	int ret = 0;

	for (i = 1; i < argc; ++i) {
		switch(argv[i][1]) {
			case 't': args->thrs = atoi(argv[++i]); break;
			case 'd': args->idir = argv[++i];       break;
			case 'o': args->odir = argv[++i];       break;

			default: fprintf(stderr, "Unknown option '%s'\n", argv[i]); ret = 1; break;
		}
	}

	if ((args->idir == NULL) || (args->odir == NULL)) {
		fprintf(stderr, "Must specify at both an input directory (-d) and an output directory (-o)\n");
		ret = 2;
	} 
	else if (!strcmp(args->idir,args->odir)) {
		fprintf(stderr, "Input and output directory cannot be the same\n"); // Otherwise it gets messy
		ret = 3;
	}

	return ret;
}



int main(int argc, char ** argv)
{
	args_t args = {0};
	args.thrs = 1; // One thread by default

	if (parse_args(&args, argc, argv)) {
		fprintf(stderr, "Error parsing args\n");
		return 1;
	}

	thread_main(args.idir, args.odir, args.thrs);

	return 0;
}
