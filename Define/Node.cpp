#include "../Declare/Node.h"

Node::Node()
{
    next = nullptr;
    prev = nullptr;
    key = "";
}
Node::Node(const Word &word)
{
    key = word.getName();
    data = word;
    next = nullptr;
    prev = nullptr;
}


string Node::getKey() const
{
    return key;
}

void Node::setKey(const string &newKey)
{
    key = newKey;
}

Word Node::getData() const
{
    return data;
}

void Node::setData(const Word &newData)
{
    data = newData;
}

Node* Node::getNext() const
{
    return next;
}

void Node::setNext(Node *newNext)
{
    next = newNext;
}

Node* Node::getPrev() const
{
    return prev;
}

void Node::setPrev(Node *newPrev)
{
    prev = newPrev;
}
