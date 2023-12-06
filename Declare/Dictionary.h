#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "../Define/HashTable.cpp"

class Dictionary
{
private:
    HashTable wordTable;
    string fileName = "data.txt";
public:
    Dictionary();
    ~Dictionary();

    // Control
    void mainMenu();                                                                         // Mennu chính
    void dictionaryMenu();                                                                   // Các chức năng chính của ứng dụng nằm trong này
    void introduction();                                                                     // Giới thiệu về chương trình
    void addWord();                                                                          // Hàm thêm từ
    void update();                                                                           // Hàm sửa từ
    void deleteWord(const int index);                                                     // Hàm xóa từ
    void search();                                                                           // Hàm tìm kiếm từ
    DoublyLinkedList searchInList(const string &query, DoublyLinkedList *dataList);          // Hàm trả về danh sách các từ chứa chuỗi được nhập
    void speak(const string &text);                                                          // Hàm phát âm tiếng Anh
    int numbersOfPage();                                                                     // Trả về số trang hiển thị của listKey
    void displayStatus(int currentWord, int currentPage);                                    // Hàm hiển thị số từ, số trang
    void displayDetail(Word word, short x, short y);                                         // Hàm hiển thị chi tiết tên, loại, nghĩa và ví dụ của từ vựng
    void displayListKey(const int &current_Word, const int &current_Page, short x, short y); // Hàm in ra danh sách tên từ
    void wordSelected(int indexKey);                                                         // Hiển thị danh sách

    // File
    void loadFromFile(const string& fileName);
    void saveToFile(const string& fileName);

    // UI
    void mainBox();                                              // In khung của
    void searchBox();                                            // 
    short choice();                                              // Trả về button được chọn
    void createBox(short x, short y, short width, short height); // Tạo khung tứ giác
};

#endif