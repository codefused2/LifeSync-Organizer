#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
using namespace std;

class Note;

struct HashNode {
    string key;
    Note* value;
    HashNode* next;
};

class HashMap {
private:
    HashNode* table[97];
    int tableSize;

public:
    HashMap();
    int hashFunction(string key);
    void insert(string key, Note* value);
    Note* find(string key);
    bool isEmpty();
    void displayAll();
    HashNode** getTable();
    int getTableSize() ;
};

#endif
