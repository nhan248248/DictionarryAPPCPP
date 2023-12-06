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

void HashTable::deleteKey(const string& key){
    int index = hashFunction(key);
    listItems[index].deleteNodeByKey(key);
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

bool HashTable::keyFound(const string &nameKey)
{   
    int index = hashFunction(nameKey);

    DoublyLinkedList* currentList = &listItems[index];

    Node* currentNode = currentList->getHead();
    while (currentNode != nullptr) {
        if (currentNode->getData().getName() == nameKey) {
            return true;
        }
        currentNode = currentNode->getNext();
    }
    return false;
}

void HashTable::loadFromFile(const string& filename) {
    ifstream file(filename);

    if (file.is_open()) {
        Word word;
        while (file >> word) {  
            insert(word);
        }
        file.close();
    }
}

void HashTable::saveToFile(const string& filename) {
    ofstream file(filename);

    if (file.is_open()) {
        // Duyệt qua danh sách và ghi vào file
        // Giả sử có hàm displayListKey để lấy danh sách từ HashTable
        DoublyLinkedList* list = listKey();
        for (int i = 0; i < tableSize; ++i) {
            Node* current = list[i].getHead();
            while (current != nullptr) {
                file << current->getData() << endl;
                current = current->getNext();
            }
        }

        file.close();
    }
}