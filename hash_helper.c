// This is where the helper functions will go
// 2021 Laurel Anderson

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"
#include "getWord/getWord.h"

void parse_file(FILE *fp){

    char *str1, *str2;
    // i think we need to malloc temp here. Work on this function later. 
    
    str2 = getNextWord(fp);
    
    // loop until end of the file
    // Note: this does not free the returned strings. Need to do free later
    while(1){
    
        str1 = str2; 
        str2 = getNextWord(fp);  
        
        // if at the end of the file, aka getNextWord == NULL
        if(str2 == NULL) break;
        
        // concat both words into one string with a space between them 
        strcat(str1, " ");
        strcat(str1, str2);   
        
        // here we send the pair to create an entry for the 
        printf("%s\n", str1);
        
    }
    
    return; 
}
