#include "../Declare/HashTable.h"

HashTable::HashTable()
{
    listItems = new DoublyLinkedList[tableSize];
}

HashTable::~HashTable()
{
    delete[] listItems;
}

int HashTable::hashFunction(const string &key)
{
    int hash = 0;
    for (char c : key)
    {
        hash += static_cast<int>(c);
    }
    return hash % tableSize;
}

void HashTable::insert(const Word &word)
{
    int index = hashFunction(word.getName());
    listItems[index].append(word);
}

void HashTable::deleteKey(const Word& word){
    int index = hashFunction(word.getName());
    listItems[index].deleteNode(word);
}

void HashTable::updateByKey(const string &key, const Word &newData)
{
    int index = hashFunction(key);
    listItems[index].updateNode(key, newData);
}

DoublyLinkedList *HashTable::listKey()
{
    // Tạo một danh sách liên kết mới
    DoublyLinkedList *nameList = new DoublyLinkedList;

    for (int i = 0; i < tableSize; ++i)
    {
        Node *current = listItems[i].getHead();
        while (current != nullptr)
        {
            // Nếu key trong listItems khác rỗng thì thêm data(Word) vào danh sách mới
            if (current->getData().getName() != "")
            {
                nameList->append(current->getData());
            }
            current = current->getNext();
        }
    }
    return nameList;
}

bool HashTable::keyFound(const Word &word)
{   
    int index = hashFunction(word.getName());

    DoublyLinkedList* currentList = &listItems[index];

    Node* currentNode = currentList->getHead();
    while (currentNode != nullptr) {
        if (currentNode->getData() == word) {
            return true;
        }
        currentNode = currentNode->getNext();
    }
    return false;
}

int HashTable::getTableSize() const
{
    return tableSize;
}