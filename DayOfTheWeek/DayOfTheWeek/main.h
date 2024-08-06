#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tableSize 12

typedef struct Node {
	int key;
	int value;
	struct Node* next;
} Node;

typedef struct HashTable {
	Node* table[tableSize];
} HashTable;

unsigned int hash(int key) {
	return key % tableSize;
}

HashTable* create() {
	HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
	for (int i = 0; i < tableSize; i++) {
		hashTable->table[i] = NULL;
	}
	return hashTable;
}

//insert



//print