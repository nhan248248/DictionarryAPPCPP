#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "../Define/DoublyLinkedList.cpp"

class HashTable
{
private:
    const int tableSize = 1000;
    DoublyLinkedList* listItems;
public:
    HashTable();
    ~HashTable();
    int hashFunction(const string &key);
    DoublyLinkedList* listKey();
    void insert(const Word &word);
    void deleteKey(const string& key);
    bool keyFound(const string &nameKey);
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename);   
};

#endif