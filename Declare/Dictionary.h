#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "../Define/HashTable.cpp"

enum choice{TU_DIEN, GIOI_THIEU, THOAT};
enum KEY {KEY_ADD, KEY_UPDATE, KEY_DELETE, KEY_SEARCH, KEY_ENTER, KEY_UP, KEY_DOWN, KEY_EXIT, KEY_POP, KEY_SPEAK_WORD,KEY_SPEAK_EXAMPLE, KEY_NONE};
UINT defaultCodePage = GetConsoleOutputCP();
UINT utf8CodePage = 65001;
#define TIME_DELAY 100
#define SCREEN_WIDTH 120
#define SCREEN_HEIGHT 35
#define DEFAULT_TEXT_COLOR 2 
#define WORD_SELECTED_COLOR 3
#define BACKGROUND_COLOR 5


class Dictionary
{
private:
    HashTable wordTable;
public:
    Dictionary();
    ~Dictionary();

    void checkBug();

    //Control
    void dictionaryMenu();
    void mainMenu();
    void introduction();             // Giới thiệu về chương trình
    void addWord();
    void update();
    void deleteWord();
    void search();
    DoublyLinkedList searchInList(const string& query, DoublyLinkedList* dataList);
    bool isExit(const string& query, DoublyLinkedList* list);
    void speak(const string& text);
    void displayNumberOfWord();
    void displayDetail(Word word, int x, int y);
    void displayListKey(int start, int end, int x, int y);
    bool isInputValid(const string& input);
    void upperCaseFirstLetter(HashTable table); // Chuyển chữ cái đầu thành in hoa        
    void wordSelected(int indexKey);  // Hiển thị danh sách

    //UI
    void mainBox();                  // In màn hình chính
    void searchBox();
    int choice();                    // Trả về button được chọn
    void createBox(int x, int y, int width, int height); // Tạo khung tứ giác
    void gotoxy(short x, short y);   // Di chuyển đến vị trí có tọa độ x, y trên màn hình
    void clscr();                    // Xóa màn hình
    void setConsoleTextColor(int textColor); // Đổi màu chữ

    void setBackgroundColor(int color); // Đổi màu nền
    void resetBackgroundColor();        // Đặt lại màu mặc định
    void button(string title, int x, int y, int width, int height, int textColor, int backgroundColor); // Tạo và hiển thị button
    void label(const string& title, int x, int y, int color);  // Tạo và hiển thị label
    void setTitle(const char *title);   // Đặt tên chương trình
    void setUTF8CodePage();             // Đặt Code Page về UTF8
    void setDefaultCodePage();          // Đặt Code Page về mặc định
    KEY getInputKey();                  // Lấy phím nhấn
    int showMessageBox(const char *message,const char *caption, UINT type); // Hiển thị thông báo

    //Algorithms
    bool compareFirstLetter(const Word& word1, const Word& word2); // So sánh ký tự đầu tiên của 2 tự
    void quickSort(HashTable table, int left, int right);          // Hàm sắp xếp
};


#endif