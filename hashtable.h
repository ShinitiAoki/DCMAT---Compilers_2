#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "varTypes.h"

#define HASH_SIZE 97 // Size of the hashtable
 

typedef struct Node {
    char *key; // Key is a string for now
    varTypes* content;
    struct Node *next; // Pointer to the next node in the linked list
} Node;

typedef struct Hashtable {
	Node **table; // Array of pointers to nodes
} Hashtable;

Hashtable* createHashtable();

void insert_update(Hashtable* ht, char* key, varTypes* content);
varTypes* search(Hashtable *ht, char *key);
void delete_content(Hashtable *ht, char *key);
void freeHashtable(Hashtable *ht);

void printHashtable(Hashtable* ht, int precision);


#endif