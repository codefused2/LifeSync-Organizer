#include "HashMap.h"
#include "Note.h"

HashMap::HashMap() {
    tableSize = 97;
    for (int i = 0; i < tableSize; i++) {
        table[i] = nullptr;
    }
}

int HashMap::hashFunction(string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
        hash = hash * 31 + key[i];
    }
    if (hash < 0) {
        hash = hash * -1;
    }
    return hash % tableSize;
}

void HashMap::insert(string key, Note* value) {
    int index = hashFunction(key);
    HashNode* newNode = new HashNode();
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
}

Note* HashMap::find(string key) {
    int index = hashFunction(key);
    HashNode* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return nullptr;
}

bool HashMap::isEmpty() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != nullptr) {
            return false;
        }
    }
    return true;
}
HashNode** HashMap::getTable()
{
    return table;
}

int HashMap::getTableSize()
{
    return tableSize;
}

void HashMap::displayAll() {
    for (int i = 0; i < tableSize; i++) {
        HashNode* current = table[i];
        while (current != nullptr) {
            cout << "Title: " << current->value->getTitle() << endl;
            cout << "Content: " << current->value->getContent() << endl;
            cout << "-----------" << endl;
            current = current->next;
        }
    }
}
