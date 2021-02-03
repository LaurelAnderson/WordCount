// this is where the hash implimentation will be
// 2021 Laurel Anderson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
//#include "dict/crc64.o"

// This method creates a hash table of given size
Table *table_create(int size){

    // put aside mem for the table 
    Table *table = (Table*)malloc(sizeof(Table)); 
    table->size = size; 
    table->total_col = 0; 
    table->num_items = 0; 
    table->buckets = (Entry**)calloc(table->size, sizeof(Entry*)); 
    
    // set each bucket to NULL
    for (int i=0; i<table->size; i++){
        table->buckets[i] = NULL; 
    }
    
    return table; 
    
}

// this creates a new entry for the table with a given key and string
Entry *entry_create(char *string){
    
    // put aside mem for the entry
    Entry *entry = (Entry*)malloc(sizeof(Entry));
    entry->string = string;
    
    // For every entry created, set next to NULL
    entry->next = NULL; 
    
    // Base count
    entry->count = 1; 
    
    // copy string over 
    strcpy(entry->string, string); 
    
    return entry;
    
}

// this frees a given entry 
void free_entry(Entry *entry){
    
    // free string and entry itself
    free(entry->string); 
    free(entry); 
    
}

// This frees a given table
void free_table(Table *table){
    
    Entry *free_item = NULL; 
     
    // iterate through all buckets
    for (int i=0; i<table->size; i++){
        
        Entry *ptr = table->buckets[i];
        
        // iterate through the buckets linked lists and free them
        while(ptr != NULL){
        
            // segfault happens here after indez 101
            //printf("Element in bucket: %d value: %s count: %d\n", i, ptr->string, ptr->count);
            free_item = ptr; 
            ptr = ptr->next; 
            free_entry(free_item);
            
        }   
    }       

    // free the table and the entry pointer
    printf("done with free table\n");
    free(table->buckets); 
    free(table);
    
}

// This inserts a value into the table
void insert(Entry *new_entry, Table *table){

    // this gets the hash value. Gets value from crc64 and % it with size
    // unsigned long long index = crc64(string) % table->size; 
    
    // use testhash to get the index for an entry
    int index =  test_hash(new_entry->string, table->size);
    
    //Entry *new_entry = entry_create(string); 
    Entry *temp = table->buckets[index]; 
    
    //printf("This is hash code %d which was %s\n", index, string); 
    
    // check if bucket is empty 
    if(temp == NULL){
    
        // insert into empty bucket
        table->buckets[index] = new_entry;
        //printf("We inserted at %d\n", index);
        table->num_items++;   
        
    }else{
    
        // handle collisions
        //printf("There was a collision at %d.\n", index);
        table->total_col++;
        
        // send to function that will preform separate chaining 
        collision(table, table->buckets[index], new_entry);
            
    }
    
}

// This handles collisions by separate chaining
void collision(Table *table, Entry *linklist_start, Entry *new_entry){

    // set num of items in that LL and set an iterator 
    Entry *iter = linklist_start;
    
    // iterates until one of the break points is found
    while(1){
        
        // if there is the same element in the list
        if (strcmp(iter->string, new_entry->string) == 0){
            
            // free the entry and increment the bucket count up by one
            free_entry(new_entry); 
            iter->count++;   
            break; 
        
        // else if you are at the end of the list  
        }else if(iter->next == NULL){

            // set the last element to new_entry
            iter->next = new_entry; 
            table->num_items++;
            break;

        }
        
        iter = iter->next;    
        
    }

    // once here we have inserted at the end of LL or incremented a count

}

// Test hashing function
int test_hash(char *string, int size){
    
    int ret_num = 0; 
    
    // add ascii values of chars in string
    for (int i = 0; i < strlen(string); i++) ret_num += string[i]; 
    
    // return a value that will fit in the hash
    return (ret_num % size); 
    
}

// This is the function that grows a table 
void grow(Table *main_table){ 

    // create a new table of original table size * 3
    Table *new_table = table_create((main_table->size)*3); 

    Table *temp_table = NULL; 
    Entry *ptr = NULL; 
    Entry *copy = NULL;
    int count = 0;  

    // iterate though buckets
    for(int i = 0; i < main_table->size; i++){

        ptr = main_table->buckets[i];

        //iterate through the linked list
        while(ptr != NULL){

            // create a copy of the given entry
            copy = entry_create(ptr->string); 
            copy->count = ptr->count; 

            // hash entry into new table
            insert(copy, new_table);
             
            ptr = ptr->next; 

        }
               
    }  

    Entry **temp = NULL; 

    temp = main_table->buckets; 
    main_table->buckets = new_table->buckets; 
    new_table->buckets = temp; 

    // Switch counts
    count = main_table->size; 
    main_table->size = new_table->size;
    new_table->size = count; 

    //set total collisions back to 0
    main_table->total_col = 0;

    printf("Freeing old table\n");

    printf("Main table content %s\n", main_table->buckets[0]->string);

    //free old table
    free_table(new_table);  

}




