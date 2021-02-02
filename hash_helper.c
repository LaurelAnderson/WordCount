// This is where the helper functions will go
// 2021 Laurel Anderson

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"
#include "getWord/getWord.h"

void parse_file(FILE *fp, Table *table){

    char *str1 = NULL;
    char *str2 = NULL;
    char *string_pair = NULL; 
    Entry *string_entry = NULL;    
    
    str2 = getNextWord(fp); 
    
    // loop until end of the file
    // Note: this does not free the returned strings. Need to do free later
    while(1){
    
        // if prev == null
        if(str1 == NULL){
        
             str1 = str2;  
               
        }else{
            
            str2 = getNextWord(fp);  
            
            // if at the end of the file, aka getNextWord == NULL
            if(str2 == NULL) break;
            
            // allocate space for both strings, a space, and a \0
            string_pair = (char *)malloc(strlen(str1) + strlen(str2) + 2);
            
            // concat both words into one string with a space between them 
            strcpy(string_pair, str1); 
            strcat(string_pair, " "); 
            strcat(string_pair, str2);   
            
            // create a fresh entry for the word pair
            string_entry = entry_create(string_pair);

            // here we send the new entry to insert into the table
            //insert(string_pair, table);
            insert(string_entry, table);
            

            // This is where the issue is
            //if we have a cirtain amount of collisions, create a new bigger hash, 
            // if (table->total_col > 10){
                 
            //     printf("We need more room!!! Calling grow!\n");
            //     grow(table); 

            // }
            
            
            free(str1);
            str1 = NULL; 
            
        }
          
    }
    
    // free strings
    free(str1); 
    free(str2);
    
    return; 

}
