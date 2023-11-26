#pragma once
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include"../Define/Node.cpp"


class DoublyLinkedList {

  public:
    Node * head;
    Node * tail;
    DoublyLinkedList();
    DoublyLinkedList(Node * n);
    ~DoublyLinkedList();

    bool isEmpty() const;
    void append(const Word& word);
    Word at(int index);
    int size() const;
    void swapNodes(DoublyLinkedList* list, int i, int j);
    bool compareFirstLetter(const Word& word1, const Word& word2);
    void quickSort(DoublyLinkedList* listWords, int left, int right);
};


#endif