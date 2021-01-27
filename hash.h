// hash.h header file
// 2021 Laurel Anderson

#include <stdio.h>
#ifndef HASH_H
#define HASH_H

// this is the structure for each entry to the hashtable
// it keeps track of hashed key, contents, collisions for that bucket, and next entry
typedef struct Entry{

    char *key; 
    char *string; 
    int collisions;
    struct Entry *next; 
    
}Entry;

// this is the structure for the hashtablel wrapper of each entry. 
// it keeps track of teh size, total collisions for the entire table, and the array of entries
typedef struct Table{

    int size; 
    int total_col; 
    Entry **buckets; 
        
}Table; 

// This method creates a hash table of given size
Table *table_create(int size);

// this creates a new entry for the table with a given key and string
Entry *entry_create(char *key, char *string); 

// This takes in a file and isolates the word pairs to be hashed. 
void parse_file(FILE*); 

#endif
