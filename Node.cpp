#include "Node.h"

Node::Node(const Word &word)
{
    data = word;
    next = nullptr;
    prev = nullptr;
}

Node::~Node()
{
}

