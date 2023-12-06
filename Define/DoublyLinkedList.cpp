#include "../Declare/DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
    head = NULL;
}
DoublyLinkedList::DoublyLinkedList(Node *n)
{
    head = n;
}

DoublyLinkedList::~DoublyLinkedList()
{
    // Hủy danh sách và giải phóng bộ nhớ
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->getNext();
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

bool DoublyLinkedList::isEmpty() const
{
    return head == nullptr;
}

Node *DoublyLinkedList::findNodeByKey(const string &key)
{
    Node *current = head;

    while (current != nullptr)
    {
        if (current->getKey() == key)
        {
            return current;
        }

        current = current->getNext();
    }

    return nullptr;
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
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
}

void DoublyLinkedList::updateNode(const string &key, const Word &newData)
{
    Node *nodeToUpdate = findNodeByKey(key);
    
    if (nodeToUpdate != nullptr)
    {
        nodeToUpdate->setData(newData);
    }
}

void DoublyLinkedList::deleteNode(const Word &word)
{
    Node *current = head;

    while (current != nullptr)
    {
        if(current->getData() == word) break;
        current = current->getNext();
    }

    if (current == nullptr)
    {
        return;
    }
    Node *prevNode = current->getPrev();
    Node *nextNode = current->getNext();

    if (prevNode != nullptr)
    {
        prevNode->setNext(nextNode);
    }
    else
    {
        head = nextNode;
    }

    if (nextNode != nullptr)
    {
        nextNode->setPrev(prevNode);
    }
    else
    {
        tail = prevNode;
    }
    delete current;
}

Word DoublyLinkedList::at(int index)
{
    Node *current = head;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < index)
    {
        current = current->getNext();
        currentIndex++;
    }

    if (current != nullptr)
    {
        return current->getData();
    }
    else
    {
        return Word();
    }
}

int DoublyLinkedList::size() const
{
    int count = 0;
    Node *current = head;

    while (current != nullptr)
    {
        count++;
        current = current->getNext();
    }

    return count;
}

void DoublyLinkedList::swapNodes(DoublyLinkedList *list, int i, int j)
{
    // Kiểm tra nếu i và j có giá trị hợp lệ
    if (i < 0 || j < 0 || i == j)
    {
        return;
    }

    // Tìm node tại vị trí i và j
    Node *nodeI = list->head;
    for (int k = 0; k < i; k++)
    {
        nodeI = nodeI->getNext();
    }

    Node *nodeJ = list->head;
    for (int k = 0; k < j; k++)
    {
        nodeJ = nodeJ->getNext();
    }

    // Swap dữ liệu giữa hai node
    Word temp = nodeI->getData();
    nodeI->getData() = nodeJ->getData();
    nodeJ->getData() = temp;
}

bool DoublyLinkedList::compareFirstLetter(const Word &word1, const Word &word2)
{
    char firstLetter1 = tolower(word1.getName()[0]);
    char firstLetter2 = tolower(word2.getName()[0]);
    return firstLetter1 < firstLetter2;
}

void DoublyLinkedList::quickSort(DoublyLinkedList *listWords, int left, int right)
{
    int i, j;
    if (left >= right)
        return;

    // Chọn pivot từ danh sách
    Node *pivotNode = listWords->head;
    for (int k = 0; k < (left + right) / 2; k++)
    {
        pivotNode = pivotNode->getNext();
    }
    Word pivot = pivotNode->getData();

    i = left;
    j = right;

    do
    {
        while (compareFirstLetter(listWords[i].head->getData(), pivot))
            i++;
        while (compareFirstLetter(pivot, listWords[j].head->getData()))
            j--;

        if (i <= j)
        {
            // Swap các node trong danh sách liên kết đôi, không phải swap listWords[i] và listWords[j]
            swapNodes(listWords, i, j);
            i++;
            j--;
        }
    } while (i < j);

    if (left < j)
        quickSort(listWords, left, j);
    if (right > i)
        quickSort(listWords, i, right);
}

Node *DoublyLinkedList::getHead() const
{
    return head;
}

void DoublyLinkedList::setHead(Node *newHead)
{
    head = newHead;
}

Node *DoublyLinkedList::getTail() const
{
    return tail;
}

void DoublyLinkedList::setTail(Node *newTail)
{
    tail = newTail;
}
