#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "DoublyLinkedList.cpp"

class HashTable
{
private:
    static const int tableSize = 100;
    DoublyLinkedList* listItems;
public:
    HashTable();
    ~HashTable();
    int hashFunction(const std::string &key);
    void insert(const Word &word);
    void display();
};

#endif