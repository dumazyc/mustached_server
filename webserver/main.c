# include <stdio.h>
# include <string.h>
#include "socket.h"
int main (/*int argc, char **argv*/void)
{
	/* Arnold Robbins in the LJ of February ’95 , describing RCS */
	/*if (argc>1 && strcmp (argv[1], "-advice") == 0) {
		printf ("Don’t Panic !\n");
		return 42;
	}
	printf ("Need an advice ?\n");*/
	while(1){
		creer_serveur(8080);
	}
	return 0; 
}

