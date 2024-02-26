#include "list.h"

Node* createFloatNode(float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->type = 0;
    newNode->data.value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new node with reference to another list
Node* createListNode(Node* sublist) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->type = 1;
    newNode->data.sublist = sublist;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->type == 0) {
            printf("%.2f -> ", temp->data.value);
        } else {
            printf("(List) -> ");
            printList(temp->data.sublist);
        }
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated to the list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        if (temp->type == 1) {
            freeList(temp->data.sublist);
        }
        free(temp);
    }
}