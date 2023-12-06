#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "../Define/DoublyLinkedList.cpp"

class HashTable
{
private:
    const int tableSize = 1000;
    DoublyLinkedList *listItems;

public:
    HashTable();
    ~HashTable();
    int hashFunction(const string &key);  // Trả về giá trị hash của 1 chuỗi
    DoublyLinkedList *listKey();          // Lấy danh sách từ trong HashTable
    void insert(const Word &word);        // Thêm từ vào HashTable
    void deleteKey(const Word& word);    // Xóa key trong HashTable
    bool keyFound(const Word &word); // Kiểm tra từ cần tìm có trong HashTable hay không

    int getTableSize() const;
};

#endif