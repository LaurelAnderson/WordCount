// This is where the helper function will go
// 2021 Laurel Anderson

#include <stdio.h>
#include "hash.h"
#include "getWord/getWord.h"

void parse_file(FILE *fp){

    char *str1, *str2, *prevStr;
    
    str2 = getNextWord(fp);
    
    // loop until end of the file
    // Note: this does not free the returned strings. Need to do later. 
    while(1){
    
        str1 = str2; 
        str2 = getNextWord(fp);  
        
        // if at the end of the file, aka getNextWord == NULL
        if(str2 == NULL) break; 
        
        printf("%s %s\n", str1, str2);
        
    }
    
    return; 
}
