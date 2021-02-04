// 2021 Laurel Anderson

/*
	For this program, I keep track of both the total collisions in a table and 
	the number of items in the table. To grow my table, Prof. McCamish gave me
	the idea to check for the average depth of each bucket of the table as 
	I insert. I decided on this relation (table->num_items/table->size > 3) to 
	decide when I grow. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"   

int main( int argc, char *argv[] )  {
    
    // start the table at size 100 
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
		
		// open file and send it to parse_file()
		FILE *fp = fopen(argv[i], "r");

		//Check if file opened correctly
		if (fp == NULL) {

    		fprintf(stderr, "ERROR: file did not open correctly.\n");
    		free_table(test); 
    		fclose(fp); 
    		return 1;

		}

		// send to parse the given file
		parse_file(fp, test); 
		
		fclose(fp);

	}
	
	// After everything is done, qsort and print the entries
	sort_table(test, num);
	
	// free the table
	free_table(test);   
	
	return 0; 

}
