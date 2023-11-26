#include "../Declare/HashTable.h"

HashTable::HashTable()
{
    listItems = new DoublyLinkedList[tableSize];
}

HashTable::~HashTable()
{
    delete[] listItems;
}

int HashTable::hashFunction(const std::string &key)
{
    int hash = 0;
    for (char c : key)
    {
        hash += static_cast<int>(c);
    }
    return hash % tableSize;
}

int HashTable::size(){
    int count = 0;
    for (int i = 0; i < tableSize; i++)
    {
        Node *current = listItems[i].head;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
    }
    return count;
}

void HashTable::insert(const Word &word)
{
    int index = hashFunction(word.getName());
    listItems[index].append(word);
}

DoublyLinkedList* HashTable::listKey() {
    // Tạo một danh sách liên kết mới
    DoublyLinkedList* nameList = new DoublyLinkedList;

    for (int i = 0; i < tableSize; ++i) {
        Node* current = listItems[i].head;
        while (current != nullptr) {
            // Thêm tên của từ vựng vào danh sách liên kết mới
            if(current->data.getName() != ""){
                nameList->append(current->data);
            }
            current = current->next;
        }
    }

    return nameList;
}

int HashTable::getTableSize(){
    return tableSize;
}