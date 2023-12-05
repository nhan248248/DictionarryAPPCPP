#pragma once
#ifndef NODE_H
#define NODE_H
#include "../Define/Word.cpp"

class Node
{
private:
    // proverties
    string key;
    Word data;
    Node *next;
    Node *prev;

public:
    // methods
    Node();
    Node(const Word &word);
    string getKey() const;
    void setKey(const string &newKey);
    Word getData() const;
    void setData(const Word &newData);
    Node *getNext() const;
    void setNext(Node *newNext);
    Node *getPrev() const;
    void setPrev(Node *newPrev);
};

#endif