#include <stdio.h>
#include <stdlib.h>

/**
 * QUESTION: Implement a Hash Table with Linear Probing for collision resolution.
 * 
 * ALGORITHM:
 * 1. Find the index: `hash = key % TABLE_SIZE`.
 * 2. If `table[index]` is empty, insert the key.
 * 3. If full (Collision), search for the next available index using `(index + 1) % TABLE_SIZE`.
 */

#define SIZE 10

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1; // -1 indicates empty slot
}

void insert(int key) {
    int index = key % SIZE;
    int originalIndex = index;

    // Linear Probing: Look for next empty slot
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == originalIndex) {
            printf("Hash Table is Full! Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

int search(int key) {
    int index = key % SIZE;
    int originalIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;
        index = (index + 1) % SIZE;
        if (index == originalIndex) break;
    }
    return -1;
}

void display() {
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: EMPTY\n", i);
    }
}

int main() {
    init();

    insert(12);
    insert(25);
    insert(35); // Collision with 25
    insert(45); // Collision with 25
    
    display();

    int key = 35;
    int res = search(key);
    if (res != -1)
        printf("\nKey %d found at index %d\n", key, res);
    else
        printf("\nKey %d not found\n", key);

    return 0;
}
