#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "getWord/getWord.h"

int main( int argc, char *argv[] )  {


	// ERROR: cheak if there are the approprate amount of args
	if (argc < 2) {
	
		fprintf(stderr, "ERROR: You need to pass at least 1 file to the program\n"); 
		return 1; 
	}

	char *str; 
	FILE *fp = fopen(argv[1], "r");
	
	str = getNextWord(fp);
	printf("%s\n", str); 
	
	free(str); 
	fclose(fp);
	
	return 0; 
	
}
