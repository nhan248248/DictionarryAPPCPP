#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
  head = NULL;
}
DoublyLinkedList::DoublyLinkedList(Node *n)
{
  head = n;
}

bool DoublyLinkedList::isEmpty(Node *n) const
{
  return head == nullptr;
}

void DoublyLinkedList::append(const Word &word)
{
  Node *newNode = new Node(word);
  if (head == nullptr)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}
