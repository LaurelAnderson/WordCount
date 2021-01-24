#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "getWord/getWord.h"

int main( int argc, char *argv[] )  {


	// cheak if there are the approprate amount of args
	if (argc < 2){
	
		fprintf(stderr, "ERROR: You need to pass at least 1 file to the program\n"); 
		return 1; 
		
	}
	
	int start;
	char *ptr = argv[1]; 
	int num = strtol(ptr, &ptr, 10); 
	
	// check if the first argument is a num
	if (*ptr == '\0'){
	 	
	 	//check to make sure you don't only have a number. 
		if (argc == 2){
			fprintf(stderr, "ERROR: specify a file to parse.\n"); 
			return 1; 
		}
		
		// set argument start point to 2
		start = 2; 
		printf("First argument is number %d and second is %s\n", num, argv[2]); 
		
	}else{ 
	
		// set argument start point to 1
		start = 1; 
		printf("First argument is not a number\n"); 
		
	}
	
	// Iterate through all text files passed as arguments
	for (int i = start; i < argc; i++){
		
		printf("Parsing file %s...\n", argv[i]);

	}
	
	/*
	char *str; 
	FILE *fp = fopen(argv[1], "r");
	
	str = getNextWord(fp);
	printf("%s\n", str); 
	
	free(str); 
	fclose(fp);
	*/
	
	return 0; 
	
}
