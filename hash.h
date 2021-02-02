// hash.h header file
// 2021 Laurel Anderson

#include <stdio.h>
#ifndef HASH_H
#define HASH_H

// this is the structure for each entry to the hashtable
// it keeps track of hashed key, contents, collisions for that bucket, and next entry
typedef struct Entry{

    char *string; 
    int count;
    struct Entry *next; 
    
}Entry;

// this is the structure for the hashtablel wrapper of each entry. 
// it keeps track of the size, total collisions for the entire table, and the array of entries
typedef struct Table{

    int size;
    int num_items;  
    int total_col; 
    Entry **buckets; 
        
}Table; 

// This method creates a hash table of given size
Table *table_create(int size);

// this creates a new entry for the table with the string
Entry *entry_create(char *string); 

// this frees a given entry 
void free_entry(Entry *entry); 

// This frees a given table
void free_table(Table *table); 

// This inserts a value into the table
void insert(Entry *entry, Table *table); 

// This handles collisions by separate chaining
void collision(Table *table, Entry *linklist_start, Entry *new_entry); 

// This is a test hash function
int test_hash(char *string, int size); 

// This takes in a file and isolates the word pairs to be hashed. 
void parse_file(FILE*, Table *table); 

// This is the function that grows a table 
void grow(Table *table); 

#endif
