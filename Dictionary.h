#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "HashTable.cpp"

class Dictionary
{
private:
    HashTable wordTable;
public:
    Dictionary();
    ~Dictionary();

    //UI
    void addWord();
    void display();
    void mainMenu();


};


#endif