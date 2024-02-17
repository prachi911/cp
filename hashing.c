#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100
struct Client {
    char name[50];
    char phone[15];
};

struct HashTableEntry {
    char name[50];
    struct Client client;
};

struct HashTable {
    struct HashTableEntry table[TABLE_SIZE];
};

void initHashTable(struct HashTable *hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        strcpy(hashTable->table[i].name, "");
    }
}

int hashFunction(char name[50]) {///////////////////////////////////

    int index = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        index += name[i];
    }
    return index % TABLE_SIZE;
}

void insert(struct HashTable *hashTable, char name[50], char phone[15]) {
    int index = hashFunction(name);
    strcpy(hashTable->table[index].name, name);
    strcpy(hashTable->table[index].client.phone, phone);
}

void search(struct HashTable *hashTable, char name[50]) {
    int index = hashFunction(name);
    if (strcmp(hashTable->table[index].name, name) == 0) {
        printf("Client Found: %s, %s\n", name, hashTable->table[index].client.phone);
    } else {
        printf("Client with name %s not found\n", name);
    }
}

int main() {
    struct HashTable hashTable;
    initHashTable(&hashTable);
  
    insert(&hashTable, "a", "1673423");
    insert(&hashTable, "b", "7651239");

    search(&hashTable, "a");
    search(&hashTable, "b");
    search(&hashTable, "c");
return 0;
}
