#pragma once
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "../Define/Node.cpp"

class DoublyLinkedList
{
private:
  Node *head;
  Node *tail;

public:
  DoublyLinkedList();
  DoublyLinkedList(Node *n);
  ~DoublyLinkedList();

  bool isEmpty() const;
  Node *findNodeByKey(const string &key);
  void append(const Word &word);
  void updateNode(const string &key, const Word &newData);
  void deleteNode(const Word &word);
  Word at(int index);
  int size() const;
  
  void swapNodes(DoublyLinkedList *list, int i, int j);
  bool compareFirstLetter(const Word &word1, const Word &word2);
  void quickSort(DoublyLinkedList *listWords, int left, int right);

  Node *getHead() const;
  void setHead(Node *newHead);
  Node *getTail() const;
  void setTail(Node *newTail);
};

#endif