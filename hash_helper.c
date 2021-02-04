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
            insert(string_entry, table);

            // grow if greater average of all hashes
            if (table->num_items/table->size > 3){
                 
                grow(table); 

            }
            
            // free and reset strings
            free(str1);
            str1 = NULL; 
            
        }
          
    }
    
    // free strings
    free(str1); 
    free(str2);
    
    return; 

}

// This function unhashes all structs and puts them in an array 
void sort_table(Table *table, int num){

    Entry *ret_arr[table->num_items];
    int iter = 0;  

    int arr_count = 0; 

    // iterate through the table
    for (int i = 0; i<table->size; i++){

        Entry *ptr1 = table->buckets[i]; 
        Entry *ptr2 = NULL; 

        while(ptr1 != NULL){

            ptr2 = ptr1->next; 
            ret_arr[arr_count] = ptr1; 
            arr_count++; 
            ptr1 = ptr2; 

        }

    }

    // sort the array 
    qsort(ret_arr, table->num_items, sizeof(Entry*), compare); 

    // if there is a number argument,
    if (num != 0){

        // set the iterator number to the argument. 
        iter = num; 

        // check for -
        if (num < 0){

            iter = -iter; 

        }
        
    }else{

        // else, print all the values in the array.
        iter = table->num_items;

    }

    // print all the values to stdout
    for(int i = 0; i<iter; i++){

        printf("%10d %s\n", ret_arr[i]->count, ret_arr[i]->string);
        
    }

    return; 

}

// qsort compare function
int compare(const void *a, const void *b){

    Entry *data_1 = *(Entry**)a; 
    Entry *data_2 = *(Entry**)b; 

    if(data_1->count > data_2->count){

        return -1; 

    }else if(data_1->count < data_2->count){

        return 1; 

    }else{

        return 0; 

    }
}