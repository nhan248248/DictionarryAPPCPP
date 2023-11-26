#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "../Define/DoublyLinkedList.cpp"

class HashTable
{
private:
    static const int tableSize = 1000;
    DoublyLinkedList* listItems;
public:
    HashTable();
    ~HashTable();
    int hashFunction(const string &key);
    int size();
    DoublyLinkedList* listKey();
    void insert(const Word &word);
    int getTableSize();
};

#endif