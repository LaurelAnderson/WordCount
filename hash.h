// hash.h header file
// 2021 Laurel Anderson

/*
Interface for this application is ./wordpair <-#> file.txt <file2.txt> ...
You can have as many text files as you want, but you need to have at least
one file. The first argument can be a number if required. The hash table is 
interfaced with the main method then parse file. The main method takes in 
user input, organizes it, and sends it to parse. The parse file then iterates
the given argument and sends word pairs to the hash table. 
*/

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

// This takes in a file and isolates the word pairs to be hashed. 
void parse_file(FILE*, Table *table); 

// This is the function that grows a table 
void grow(Table *table); 

// This function unhashes all structs and puts them in an array 
void sort_table(Table *table, int num); 

// This is the qsort compare function
int compare(const void *a, const void *b);

#endif
