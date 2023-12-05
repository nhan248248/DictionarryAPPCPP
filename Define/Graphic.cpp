#include "../Declare/Graphic.h"

Graphic::Graphic()
{
}
Graphic::~Graphic()
{
}

void Graphic::gotoxy(short x, short y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Graphic::clscr()
{
    system("cls");
}

// Đổi màu chữ
void Graphic::setConsoleTextColor(const short color[])
{
    cout << "\033[38;2;" << color[0] << ";" << color[1] << ";" << color[2] << "m";
}

void Graphic::setBackgroundColor(const short color[])
{
    // Sử dụng mã màu và chuỗi escape ANSI để đặt màu nền
    cout << "\033[48;2;" << color[0] << ";" << color[1] << ";" << color[2] << "m";
}

void Graphic::displayBackgroundColor()
{
    setBackgroundColor(background_Color);
    gotoxy(0, 0);
    for (int i = 0; i < 4200; i++)
    {
        cout << " ";
    }
    // resetColor();
}

void Graphic::resetColor()
{
    cout << "\033[0m"; // Đặt mã màu về mặc định
}

void Graphic::button(string title, short x, short y, short width, short height, const short textColor[], const short backgroundColor[])
{
    setBackgroundColor(backgroundColor);
    short midPos = x + 3 + (width - title.length()) / 2;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gotoxy(x + j, y);
            cout << "  ";
        }
        y++;
        cout << "\n";
    }
    setBackgroundColor(shadow_Color);
    for (int i = 0; i < height; i++)
    {
        gotoxy(x - 1, y - i);
        cout << " ";
    }
    for (int i = 0; i < width - 1; i++)
    {
        gotoxy(x + i, y);
        cout << " ";
    }
    resetColor();

    setBackgroundColor(backgroundColor);
    gotoxy(midPos, y - (height + 1) / 2);
    setConsoleTextColor(textColor);
    cout << title;
    resetColor();
}

void Graphic::label(const string &title, short x, short y, const short textColor[])
{

    // Đảm bảo rằng x và y không vượt quá giới hạn của màn hình
    if (x >= 0 && y >= 0 && x < SCREEN_WIDTH && y < SCREEN_HEIGHT)
    {
        gotoxy(x, y);
        setConsoleTextColor(textColor);
        // In ra màn hình không vượt quá giới hạn
        cout << title.substr(0, SCREEN_WIDTH - x);
    }
}

void Graphic::setTitle(const char *title)
{
    SetConsoleTitleA(title);
}

// Đặt codePage thành UTF8
void Graphic::setUTF8CodePage()
{
    system("MODE CON: CP SELECT=65001 > nul");
}

// Trả codePage về mặc định
void Graphic::setDefaultCodePage()
{
    SetConsoleOutputCP(defaultCodePage);
}

// Đưa ra thông báo
int Graphic::showMessageBox(const char *message, const char *caption, UINT type)
{
    HWND cur_window = GetConsoleWindow();

    // Chuyển đổi chuỗi char thành chuỗi wchar_t
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, message, -1, NULL, 0);
    wchar_t *w_message = new wchar_t[size_needed];
    MultiByteToWideChar(CP_UTF8, 0, message, -1, w_message, size_needed);

    int size_needed_caption = MultiByteToWideChar(CP_UTF8, 0, caption, -1, NULL, 0);
    wchar_t *w_caption = new wchar_t[size_needed_caption];
    MultiByteToWideChar(CP_UTF8, 0, caption, -1, w_caption, size_needed_caption);

    int result = MessageBoxW(cur_window, w_message, w_caption, type);

    delete[] w_message;
    delete[] w_caption;

    return result;
}

KEY Graphic::getInputKey()
{
    int KeyPressed = 0;
    KEY key = KEY_NONE;

    while (!KeyPressed)
    {
        fflush(stdin);

        if (GetAsyncKeyState(VK_MENU) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_ADD;
        }
        else if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_UPDATE;
        }
        else if (GetAsyncKeyState(VK_DELETE) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_DELETE;
        }
        else if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_SEARCH;
        }
        else if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_UP;
        }
        else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_DOWN;
        }
        else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_LEFT;
        }
        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_RIGHT;
        }
        else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_ENTER;
        }
        else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_EXIT;
        }
        else if (GetAsyncKeyState(VK_BACK) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_POP;
        }
        else if (GetAsyncKeyState(VK_F1) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_SPEAK_WORD;
        }
        else if (GetAsyncKeyState(VK_F2) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_SPEAK_EXAMPLE;
        }
        fflush(stdin);
    }

    fflush(stdin);
    return key;
}
