// this is where the hash implimentation will be
// 2021 Laurel Anderson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

// This method creates a hash table of given size
Table *table_create(int size){

    // put aside mem for the table 
    Table *table = (Table*)malloc(sizeof(Table)); 
    table->size = size; 
    table->total_col = 0; 
    table->buckets = (Entry**)calloc(table->size, sizeof(Entry*)); 
    
    // set each bucket to NULL
    for (int i=0; i<table->size; i++){
        table->buckets[i] = NULL; 
    }
    
    return table; 
    
}

// this creates a new entry for the table with a given key and string
Entry *entry_create(char *key, char *string){
    
    // put aside mem for the entry
    Entry *entry = (Entry*)malloc(sizeof(Entry));
    entry->key = (char*)malloc(strlen(key)+1); 
    entry->string = (char*)malloc(strlen(string)+1);
    entry->collisions = 0; 
    
    // copy items over
    strcpy(entry->key, key); 
    strcpy(entry->string, string); 
    
    return entry;
    
}
