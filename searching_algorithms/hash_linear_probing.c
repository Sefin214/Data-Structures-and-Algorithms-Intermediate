#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10

// State markers for the hash table
#define EMPTY -1
#define DELETED -2

int hashTable[TABLE_SIZE];

// Initialize the hash table with EMPTY markers
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Basic modulo hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Store a key using Linear Probing
bool insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;

    // Probe until an EMPTY or DELETED slot is found
    while (hashTable[index] != EMPTY && hashTable[index] != DELETED) {
        // Prevent duplicate keys
        if (hashTable[index] == key) {
            printf("Key %d already exists at index %d.\n", key, index);
            return false;
        }
        
        i++;
        index = (originalIndex + i) % TABLE_SIZE; // Linear probe formula
        
        // If we loop back to the start, the table is completely full
        if (index == originalIndex) {
            printf("Hash table is full! Cannot insert %d.\n", key);
            return false;
        }
    }
    
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
    return true;
}

// Find a key using Linear Probing
int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;

    // Probe as long as the slot is NOT completely EMPTY
    // (We must continue searching if we hit a DELETED slot)
    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            return index; // Key found! Return its array index
        }
        
        i++;
        index = (originalIndex + i) % TABLE_SIZE;
        
        // Break if we've searched the entire table and returned to the start
        if (index == originalIndex) {
            break; 
        }
    }
    
    return -1; // Key not found
}

int main() {
    initTable();

    // Inserting elements
    insert(42); // 42 % 10 = 2 -> Placed at index 2
    insert(15); // 15 % 10 = 5 -> Placed at index 5
    
    // Forcing Collisions
    insert(25); // 25 % 10 = 5 (Collision!) -> Probes to index 6
    insert(35); // 35 % 10 = 5 (Collision!) -> Probes to index 7
    
    printf("\n--- Searching ---\n");
    
    int result = search(25);
    if (result != -1) {
        printf("Key 25 found at index %d\n", result);
    } else {
        printf("Key 25 not found\n");
    }
    
    result = search(99);
    if (result != -1) {
        printf("Key 99 found at index %d\n", result);
    } else {
        printf("Key 99 not found\n");
    }

    return 0;
}