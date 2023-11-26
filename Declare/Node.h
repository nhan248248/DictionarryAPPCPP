#pragma once
#ifndef NODE_H
#define NODE_H
#include "../Define/Word.cpp"

class Node
{
public:
    //proverties
    Word data;
    Node *next;
    Node *prev;

public:
    //methods
    //Node();
    Node(const Word &word);
    ~Node();
};

#endif