#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
    int type;  // 0 for float, 1 for list
    union {
        float value;            // Value if type is 0
        struct Node* sublist;   // Reference to sublist if type is 1
    } data;
    struct Node* next;  // Pointer to the next node
} Node;

Node* createFloatNode(float value);

// Function to create a new node with reference to another list
Node* createListNode(Node* sublist);
// Function to insert a node at the end of the list
void insertNode(Node** head, Node* newNode);

// Function to print the linked list
void printList(Node* head);

// Function to free the memory allocated to the list
void freeList(Node* head);