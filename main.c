// 2021 Laurel Anderson

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"   

int main( int argc, char *argv[] )  {

    /*
    // This part was set up to test the hashing function without the rest of the code
    Table *test = table_create(100);
    insert("hello there", test);  
    insert("general kenobi", test); 
    insert("hello there", test);
    //free_table(test); 
    */
    
    Table *test = table_create(100);
    
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
		
	}else{ 
	
		// set argument start point to 1
		start = 1;  
		
	}
	
	// Iterate through all text files passed as arguments
	for (int i = start; i < argc; i++){
		
		printf("Parsing file %s...\n", argv[i]);
		
		// open file and send it to parse_file()
		FILE *fp = fopen(argv[i], "r");
		parse_file(fp, test); 
		printf("---------Number of items in table = %d-----------\n", test->num_items); 
		printf("---------Number of collisions in table = %d-----------\n", test->total_col);
		fclose(fp);

	}    
	
	return 0; 

}
