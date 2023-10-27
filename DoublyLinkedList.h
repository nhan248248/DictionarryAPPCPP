#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include"Word.cpp"
#include"Node.cpp"


class DoublyLinkedList {

  public:
    Node * head;
    Node * tail;
    DoublyLinkedList();
    DoublyLinkedList(Node * n);
    bool isEmpty(Node * n) const;
    void append(const Word& word);
};


#endif