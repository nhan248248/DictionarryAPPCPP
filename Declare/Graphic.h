#pragma once
#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <conio.h>
#include <ctype.h>
using namespace std;

enum choice
{
    TU_DIEN,
    GIOI_THIEU,
    THOAT
};
enum KEY
{
    KEY_ADD,
    KEY_UPDATE,
    KEY_DELETE,
    KEY_SEARCH,
    KEY_ENTER,
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_EXIT,
    KEY_POP,
    KEY_SPEAK_WORD,
    KEY_SPEAK_EXAMPLE,
    KEY_NONE
};
UINT defaultCodePage = GetConsoleOutputCP();
UINT utf8CodePage = 65001;
#define TIME_DELAY 130
#define SCREEN_WIDTH 120
#define SCREEN_HEIGHT 35
#define NUMBER_TO_VIEW 20

const short title_Color[] = {200, 0, 255};       // Green
const short default_Text_Color[] = {0, 255, 0};  // Green
const short word_Selected_Color[] = {0, 17, 51}; // Green blue
const short default_Background_Color[] = {0, 0, 0};

const short background_Color[] = {255, 255, 0};            // White
const short button_Color[] = {51, 153, 255};               // 
const short text_Button_Color[] = {0, 0, 0};               // Red
const short button_Choosen_Color[] = {0, 128, 255};        //
const short text_Button_Choosen_Color[] = {255, 255, 255}; // 
const short shadow_Color[] = {0, 77, 153};

const short box_Color[] = {0, 0, 0};                  //
const short text_Menu_Choice_Color[] = {0, 102, 255}; //
const short list_Key_Color[] = {0, 153, 0};           //

class Graphic
{
private:
public:
    Graphic();
    ~Graphic();

    static void gotoxy(short x, short y);                                                                                                  // Di chuyển đến vị trí có tọa độ x, y trên màn hình
    static void clscr();                                                                                                                   // Xóa màn hình
    static void setConsoleTextColor(const short color[]);                                                                                  // Đổi màu chữ
    static void setBackgroundColor(const short color[]);                                                                                   // Đổi màu nền
    static void displayBackgroundColor();                                                                                                  // Hiển thị màu nền
    static void resetColor();                                                                                                              // Đặt lại màu mặc định
    static void button(string title, short x, short y, short width, short height, const short textColor[], const short backgroundColor[]); // Tạo và hiển thị button
    static void label(const string &title, short x, short y, const short textColor[]);                                                     // Tạo và hiển thị label
    static void setTitle(const char *title);                                                                                               // Đặt tên chương trình
    static void setUTF8CodePage();                                                                                                         // Đặt Code Page về UTF8
    static void setDefaultCodePage();                                                                                                      // Đặt Code Page về mặc định
    static KEY getInputKey();                                                                                                              // Lấy phím nhấn
    static int showMessageBox(const char *message, const char *caption, UINT type);
};

#endif