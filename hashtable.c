
#include "hashtable.h"

int hash_function(char* key) {
	int hash = 0;
	for (int i = 0; key[i] != '\0'; i++) {
		hash += key[i];
	}
	return hash % HASH_SIZE;
}


Node* createNode(char* key, varTypes* content){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->content = content;
	newNode->next = NULL;
	return newNode;
}

Hashtable* createHashtable(){
	Hashtable* ht = (Hashtable*)malloc(sizeof(Hashtable));
	ht->table = (Node**)malloc(HASH_SIZE * sizeof(Node*));
	for(int i = 0; i < HASH_SIZE; i++){
		ht->table[i] = NULL;
	}
	return ht;
}

void insert_update(Hashtable* ht, char* key, varTypes* content){
	if(ht == NULL){
		return;
	}
	int index = hash_function(key);
	if(ht->table[index] == NULL){
		printf("is null, creating new node\n");
		ht->table[index] = createNode(key, content);
	}
	else{
		printf("not null, searching for duplicate\n");
		Node* temp = ht->table[index];
		Node* prev = NULL;
		while(temp != NULL){
			printf("comparing %s with %s\n", temp->key, key);
			if(strcmp(temp->key, key) == 0){
				printf("found duplicate\n");
				temp->content = content;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
		temp = createNode(key, content);
		prev->next = temp;
	}
}



varTypes* search(Hashtable *ht, char *key){
	if(ht == NULL){
		return NULL;
	}
	int index = hash_function(key);
	if(ht->table[index] == NULL){
		return NULL;
	}
	else{
		Node* temp = ht->table[index];
		while(temp != NULL){
			if(strcmp(temp->key, key) == 0){
				return temp->content;
			}
			temp = temp->next;
		}
	}
	return NULL;

}
void delete_content(Hashtable *ht, char *key){
	if(ht == NULL){
		return;
	}
	int index = hash_function(key);
	if(ht->table[index] == NULL){
		return;
	}
	else{
		Node* temp = ht->table[index];
		Node* prev = NULL;
		while(temp != NULL){
			if(strcmp(temp->key, key) == 0){
				if(prev == NULL){
					ht->table[index] = temp->next;
				}
				else{
					prev->next = temp->next;
				}
				free(temp->key);
				free(temp->content);
				free(temp);
				return;
			}
			prev = temp;
			temp = temp->next;
		}
	}
}
void freeHashtable(Hashtable *ht){
	if(ht == NULL){
		return;
	}
	for(int i = 0; i < HASH_SIZE; i++){
		Node* temp = ht->table[i];
		while(temp != NULL){
			Node* aux = temp;
			temp = temp->next;
			free(aux->key);
			free(aux->content);
			free(aux);
		}
	}
	free(ht->table);
	free(ht);
}


void printHashtable(Hashtable* ht, int precision){
	printf("Printing Hashtable:\n");
	if(ht == NULL){
		return;
	}
	for(int i = 0; i < HASH_SIZE; i++){
		Node* temp = ht->table[i];
		while(temp != NULL){
			printf("%s:\n", temp->key);
			printVarTypes(temp->content, precision);
			temp = temp->next;
		}
	}
}
void showSymbols(Hashtable* ht){
	printf("Printing Hashtable:\n");
	if(ht == NULL){
		return;
	}
	for(int i = 0; i < HASH_SIZE; i++){
		Node* temp = ht->table[i];
		while(temp != NULL){
			varTypes* content = temp->content;
			if(content->type == 1){
				printf("%s - FLOAT\n", temp->key);
			}
			else if(content->type == 2){
				printf("%s - ", temp->key);
				printf("MATRIX [%d][%d]\n", content->m->linhas, content->m->colunas);
			}
			temp = temp->next;
		}
	}
}