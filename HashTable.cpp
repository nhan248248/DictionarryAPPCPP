#include "Hashtable.h"

HashTable::HashTable()
{
    listItems = new DoublyLinkedList[tableSize];
}

HashTable::~HashTable()
{
    delete[] listItems;
}

int HashTable::hashFunction(const std::string &key)
{
    int hash = 0;
    for (char c : key)
    {
        hash += static_cast<int>(c);
    }
    return hash % tableSize;
}

void HashTable::insert(const Word &word)
{
    int index = hashFunction(word.getName());
    listItems[index].append(word);
}

void HashTable::display() 
{
    cout << "Danh sach tu vung" << endl;
    for (int i = 0; i < tableSize; i++)
    {
        Node *current = listItems[i].head;
        while (current != nullptr)
        {
            Word word = current->data;
            cout << "--------------------------"<< endl;
            cout << word;
            current = current->next;
        }
    }
}