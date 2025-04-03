#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initializeTable() {
    // Initialize all slots to -1 (indicating empty)
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

int hashFunction(int key) {
    int sum=0;
    for ( ; key ; key/=10, sum+=key%10)
    return sum%TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        printf("Collision occurred for key %d at index %d\n", key, index);
    }
}

void displayTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("[%d]: Empty\n", i);
        } else {
            printf("[%d]: %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    initializeTable();

    insert(5);
    insert(15);
    insert(25);
    insert(7);
    insert(50);
    insert(1093);

    displayTable();

    return 0;
}
