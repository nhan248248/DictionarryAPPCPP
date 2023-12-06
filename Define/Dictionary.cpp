#include "../Declare/Dictionary.h"

Dictionary::Dictionary(const string& fileName)
{
    wordTable.loadFromFile(fileName);
    mainMenu();
}
Dictionary::~Dictionary()
{
}

void Dictionary::mainMenu()
{
    short choose = choice();
    if (choose == TU_DIEN)
    {
        Graphic::clscr();
        dictionaryMenu();
    }
    else if (choose == GIOI_THIEU)
    {
        Graphic::resetColor();
        Graphic::clscr();
        introduction();
    }
    else
    {
        Graphic::clscr();
        exit(0);
    }
}

void Dictionary::introduction()
{
    int x = 50, y = 2;
    int choose;
    do
    {
        Graphic::clscr();
        Graphic::setUTF8CodePage();
        Graphic::gotoxy(x, y - 1);
        cout << "TỪ ĐIỂN ANH VIỆT";
        Graphic::gotoxy(x - 18, y + 1);
        cout << "===========================================================";
        Graphic::gotoxy(x - 18, y + 3);
        cout << "Tác giả: ";
        Graphic::gotoxy(x - 18, y + 4);
        cout << "LÊ VĂN NHÀN";
        Graphic::gotoxy(x - 18, y + 5);
        cout << "NGUYỄN THỊ NGÂN ANH" << endl;

        cout << "\t\t\t\tNội dung" << endl;
        cout << "\t\t\t\tNội dung" << endl;

        Graphic::gotoxy(x - 3, y + 30);
        cout << "Nhấn phím ESC để quay trở lại....";
        Graphic::setDefaultCodePage();
        choose = Graphic::getInputKey();
        Sleep(TIME_DELAY);
    } while (choose != KEY_EXIT);
    Graphic::clscr();
    mainMenu();
}

void Dictionary::dictionaryMenu()
{
    int choose;
    int currentWord = 0, currentPage = 0, wordIndex = 0;
    int x = 15, y = 7;
    int numbersWordInPage = 0;

    Graphic::displayBackgroundColor();
    mainBox();
    // displayListKey(index, x, y);
    // wordSelected(index);

    do
    {
        wordIndex = currentPage * NUMBER_TO_VIEW + currentWord;
        numbersWordInPage = (wordIndex / NUMBER_TO_VIEW == 0) ? NUMBER_TO_VIEW : wordTable.listKey()->size() % NUMBER_TO_VIEW;
        displayStatus(wordIndex, currentPage);
        displayListKey(currentWord, currentPage, x, y);
        wordSelected(wordIndex);
        choose = Graphic::getInputKey();

        if (choose == KEY_UP)
        {
            if (currentWord > 0)
            {
                currentWord--;
            }
            else if (currentWord == 0)
            {
                currentWord = numbersWordInPage - 1;
            }
        }
        else if (choose == KEY_DOWN)
        {
            if (currentWord < numbersWordInPage - 1)
            {
                currentWord++;
            }
            else if (currentWord == numbersWordInPage - 1)
            {
                currentWord = 0;
            }
        }
        else if (choose == KEY_LEFT)
        {
            if (currentPage < numbersOfPage() - 1)
            {
                currentPage++;
                currentWord = 0;
            }
            else if (currentPage == numbersOfPage() - 1)
            {
                currentPage = 0;
                currentWord = 0;
            }
        }
        else if (choose == KEY_RIGHT)
        {
            if (currentPage < numbersOfPage() - 1)
            {
                currentPage++;
                currentWord = 0;
            }
            else if (currentPage == numbersOfPage() - 1)
            {
                currentPage = 0;
                currentWord = 0;
            }
        }
        else if (choose == KEY_ADD)
        {
            Graphic::clscr();
            addWord();
            Graphic::clscr();
            dictionaryMenu();
        }
        else if (choose == KEY_UPDATE)
        {
            Graphic::clscr();
            Graphic::displayBackgroundColor();
            update();
            Graphic::clscr();
            dictionaryMenu();
        }
        else if (choose == KEY_DELETE)
        {
            string key = wordTable.listKey()->at(wordIndex).getName();
            deleteWord(key);
        }
        else if (choose == KEY_SEARCH)
        {
            Graphic::clscr();
            Graphic::displayBackgroundColor();
            displayStatus(wordIndex, currentPage);
            search();
            Graphic::clscr();
            dictionaryMenu();
        }
        else if (choose == KEY_SPEAK_WORD)
        {
            string text = wordTable.listKey()->at(wordIndex).getName();
            speak(text);
            continue;
        }
        else if (choose == KEY_SPEAK_EXAMPLE)
        {
            string text = wordTable.listKey()->at(wordIndex).getExample();
            speak(text);
            continue;
        }
        Sleep(TIME_DELAY);
    } while (choose != KEY_EXIT);
    // Graphic::resetColor();
    Graphic::clscr();
    mainMenu();
}
// 1. Chức năng thêm từ
void Dictionary::addWord()
{
    Word word;
    string s = "";

    Graphic::displayBackgroundColor();
    createBox(40, 10, 40, 16);
    Graphic::setUTF8CodePage();    
    
    Graphic::gotoxy(57, 8);
    Graphic::setConsoleTextColor(title_Color);
    cout << "THÊM TỪ";
    // Nhập tên từ
    do
    {
        Graphic::gotoxy(43, 11);
        Graphic::setConsoleTextColor(button_Choosen_Color);
        cout << "Tên từ: ";
        Graphic::setConsoleTextColor(word_Selected_Color);
        fflush(stdin);
        getline(cin, s);
    } while (s.empty());
    word.setName(s);

    // Nhập loại từ
    do
    {
        Graphic::gotoxy(43, 12);
        Graphic::setConsoleTextColor(button_Choosen_Color);
        cout << "Loại từ: ";
        Graphic::setConsoleTextColor(word_Selected_Color);
        fflush(stdin);
        getline(cin, s);
    } while (s.empty());
    word.setType(s);

    // Nhập nghĩa
    do
    {
        Graphic::gotoxy(43, 13);
        Graphic::setConsoleTextColor(button_Choosen_Color);
        cout << "Nghĩa: ";
        Graphic::setConsoleTextColor(word_Selected_Color);
        fflush(stdin);
        getline(cin, s);
    } while (s.empty());
    word.setMeaning(s);

    // Nhập ví dụ
    do
    {
        Graphic::gotoxy(43, 14);
        Graphic::setConsoleTextColor(button_Choosen_Color);
        cout << "Ví dụ: ";
        Graphic::setConsoleTextColor(word_Selected_Color);
        fflush(stdin);
        getline(cin, s);
    } while (s.empty());
    word.setExample(s);



    if (!wordTable.keyFound(word.getName()))
    {
        // Thêm từ vào hashtable
        wordTable.insert(word);

        // Mở tệp để ghi
        ofstream outFile("data.txt", ios::app);

        if (outFile.is_open()) {
            // Ghi thông tin từ vào tệp
            outFile << word.getName() << "/" << word.getType() << "/" << word.getMeaning() << "/" << word.getExample() << "\n";

            // Đóng tệp
            outFile.close();

            Graphic::showMessageBox("Thêm từ thành công!", "Thông báo", 0);
        } else {
            Graphic::showMessageBox("Lỗi khi mở tệp để ghi!", "Lỗi!!!", 0);
        }
    }
    else
    {
        Graphic::showMessageBox("Từ bạn vừa nhập đã có trong danh sách vui lòng nhập lại", "Lỗi!!!", 0);
        Graphic::setDefaultCodePage();
        Graphic::clscr();
        addWord();
    }
    Graphic::setDefaultCodePage();
}
// 2. Chức năng sửa
void Dictionary::update()
{
    createBox(40, 10, 40, 16);
    Graphic::setUTF8CodePage();
    
    Graphic::gotoxy(50, 2);
    cout << "Sửa từ ở đây";
    
    
    Graphic::showMessageBox("Đã sửa", "Thông báo", 0);
    Graphic::setDefaultCodePage();
}
// 3. Chức năng Xóa
void Dictionary::deleteWord(const string& name)
{
    Graphic::setUTF8CodePage();
    
    wordTable.deleteKey(name);
    
    Graphic::showMessageBox("Đã xóa", "Thông báo", 0);
    Graphic::setDefaultCodePage();
}



// 4. Chức năng tìm kiếm

// Hàm kiểm trả về danh sách từ chứa chuỗi được nhập vào
DoublyLinkedList Dictionary::searchInList(const string &query, DoublyLinkedList *dataList)
{
    DoublyLinkedList results;

    // Chuyển đổi query thành chữ thường để tìm kiếm không phân biệt chữ hoa thường
    string lowercaseQuery = query;
    transform(lowercaseQuery.begin(), lowercaseQuery.end(), lowercaseQuery.begin(), ::tolower);

    Node *current = dataList->getHead();

    while (current != nullptr)
    {
        const auto &item = current->getData();
        // Chuyển đổi tên từ thành chữ thường để so sánh
        string lowercaseName = item.getName();
        transform(lowercaseName.begin(), lowercaseName.end(), lowercaseName.begin(), ::tolower);

        if (lowercaseName.find(lowercaseQuery) != string::npos)
        {
            results.append(item);
        }
        current = current->getNext();
    }

    return results;
}

// Hàm tìm từ và hiển thị danh sách từ chứa ký tự được nhập
void Dictionary::search()
{
    Sleep(100);
    // Vị trí nhập
    short x_Input = 12, y_Input = 6;
    // Vị trí xuất danh sách
    short x_List = 15, y_List = 9;
    // Vị trí xuất chi tiết từ
    short x_Detail = 43, y_Detail = 9;
    // Vị trí con trỏ nhập
    short x_Point = 6;

    char key;
    string userInput = "";

    // getchar();

    Graphic::setUTF8CodePage();
    for (int i = 0; i < NUMBER_TO_VIEW - 2; i++)
    {
        Graphic::label(wordTable.listKey()->at(i).getName(), x_List, y_List + i, list_Key_Color);
    }

    Graphic::gotoxy(x_Input, y_Input);
    cout << "Nhập: ";
    Graphic::setDefaultCodePage();

    do
    {
        searchBox();
        Graphic::gotoxy(x_Input + x_Point, y_Input);
        fflush(stdin);
        key = _getch();

        // Xóa từng ký tự trong chuỗi vừa nhập
        if (key == '\b')
        {
            if (!userInput.empty())
            {
                x_Point--;
                userInput.pop_back();
            }
        }

        if (isalpha(key))
        {
            userInput += key;
            x_Point++;
        }

        DoublyLinkedList searchResults = searchInList(userInput, wordTable.listKey());
        if (key == 59)
        {
            string text = searchResults.at(0).getName();
            speak(text);
            continue;
        }
        else if (key == 60)
        {
            string text = searchResults.at(0).getExample();
            speak(text);
            continue;
        }

        // Làm sạch chỗ nhập và hiển thị chuỗi vừa nhập
        Graphic::gotoxy(x_Input + 6, y_Input);
        cout << "                      ";
        Graphic::gotoxy(x_Input + 6, y_Input);
        Graphic::setConsoleTextColor(word_Selected_Color);
        cout << userInput;
        Graphic::setConsoleTextColor(default_Text_Color);

        // Làm sạch danh sách
        for (int i = 0; i < NUMBER_TO_VIEW - 2; i++)
        {
            Graphic::gotoxy(x_List, y_List + i);
            cout << "                        ";
            Graphic::gotoxy(x_Point, y_Input);
        }

        Graphic::setUTF8CodePage();

        // Kiểm tra từ vừa nhập có trong danh sách không
        if (!wordTable.keyFound(userInput))
        {
            if (searchResults.size() != 1)
            {
                Graphic::gotoxy(x_Detail, y_Detail);
                cout << "                                                           ";
                Graphic::gotoxy(x_Detail, y_Detail + 2);
                cout << "                                                           ";

                Graphic::gotoxy(x_Detail, y_Detail);
                Graphic::setConsoleTextColor(word_Selected_Color);
                cout << "Từ này không có trong danh sách!!!";
            }
            // Nếu số từ trong danh sách tìm được chỉ có 1 từ thì hiển thị chi tiết từ đó ra
            else
            {
                displayDetail(searchResults.at(0), x_Detail, y_Detail);
                Graphic::gotoxy(x_Point, y_Input);
            }
        }
        else
        {
            displayDetail(searchResults.at(0), x_Detail, y_Detail);
            Graphic::gotoxy(x_Point, y_Input);
        }

        // Chưa nhập gì thì không hiển thị gì cả
        if (x_Point == 6)
        {
            Graphic::gotoxy(x_Detail, y_Detail);
            cout << "                                                           ";
            Graphic::gotoxy(x_Detail, y_Detail + 2);
            cout << "                                                           ";
        }

        // Hiển thị danh sách từ có chứa chuỗi vừa nhập
        for (int i = 0; i < searchResults.size(); i++)
        {
            if (i == NUMBER_TO_VIEW - 2)
                break;
            Graphic::label(searchResults.at(i).getName(), x_List, y_List + i, list_Key_Color);
        }
        Graphic::setDefaultCodePage();
        Sleep(TIME_DELAY);
    } while (key != 27);
}

// Định nghĩa hàm phát âm
void Dictionary::speak(const string &text)
{
    string cmdlines = ".\\Common\\TTSAPI.vbs \"" + text + "\"";
    system(cmdlines.c_str());
}

// XỬ LÝ GIAO DIỆN
void Dictionary::mainBox()
{
    Graphic::gotoxy(52, 2);
    Graphic::setUTF8CodePage();
    Graphic::setConsoleTextColor(title_Color);
    cout << "TỪ ĐIỂN ANH VIỆT";
    Graphic::setTitle("DICTIONARY APPLICATION");
    Graphic::setConsoleTextColor(default_Text_Color);

    Graphic::setDefaultCodePage();
    Graphic::setConsoleTextColor(box_Color);
    // Đường thẳng ở trên
    Graphic::gotoxy(10, 5);
    cout << char(201);
    for (int i = 0; i < 100; i++)
    {
        cout << char(205);
    }
    cout << char(187);

    // Đường thẳng ở giữa
    Graphic::gotoxy(40, 10);
    for (int i = 0; i < 72; i++)
    {
        cout << char(205);
    }

    // Đường dọc ở bên trái
    for (int i = 6; i < 30; i++)
    {
        Graphic::gotoxy(10, i);
        cout << char(186);
    }

    // Đường dọc ở bên phải
    for (int i = 6; i < 30; i++)
    {
        Graphic::gotoxy(111, i);
        cout << char(186);
    }

    // Đường thẳng ở dưới
    Graphic::gotoxy(10, 30);
    cout << char(200);
    for (int i = 0; i < 100; i++)
    {
        Graphic::gotoxy(11 + i, 30);
        cout << char(205);
    }
    cout << char(188);

    // Đường dọc ở giữa
    Graphic::gotoxy(40, 5);
    cout << char(203);
    for (int i = 6; i < 30; i++)
    {
        Graphic::gotoxy(40, i);
        cout << char(186);
    }
    Graphic::gotoxy(40, 30);
    cout << char(202);

    // Đường thẳng nhỏ ở dưới góc trái
    Graphic::gotoxy(11, 28);
    for (int i = 0; i < 29; i++)
    {
        cout << char(205);
    }

    // Các viền góc
    Graphic::gotoxy(40, 10);
    cout << char(204);
    Graphic::gotoxy(111, 10);
    cout << char(185);
    Graphic::gotoxy(40, 28);
    cout << char(185);
    Graphic::gotoxy(10, 28);
    cout << char(204);

    // In các hướng dẫn
    Graphic::gotoxy(44, 6);
    Graphic::setConsoleTextColor(text_Menu_Choice_Color);
    Graphic::setUTF8CodePage();
    cout << "ALT - THÊM      SPACE - SỬA   DELETE - XOÁ     SHIFT - TÌM KIẾM";

    Graphic::gotoxy(44, 9);
    cout << "ESC - TRỞ LẠI   F1 - ĐỌC TỪ   F2 - ĐỌC VÍ DỤ" << endl;
    Graphic::setConsoleTextColor(default_Text_Color);
    Graphic::setDefaultCodePage();
}

void Dictionary::searchBox()
{
    Graphic::gotoxy(50, 2);
    Graphic::setUTF8CodePage();
    Graphic::setConsoleTextColor(title_Color);
    cout << "TỪ ĐIỂN ANH VIỆT";

    Graphic::setDefaultCodePage();
    Graphic::setConsoleTextColor(box_Color);
    // Đường thẳng ở trên
    Graphic::gotoxy(10, 5);
    cout << char(201);
    for (int i = 0; i < 100; i++)
    {
        cout << char(205);
    }
    cout << char(187);

    // Đường thẳng ở giữa
    Graphic::gotoxy(11, 7);
    for (int i = 0; i < 100; i++)
    {
        cout << char(205);
    }

    // Đường dọc ở bên trái
    for (int i = 6; i < 30; i++)
    {
        Graphic::gotoxy(10, i);
        cout << char(186);
    }

    // Đường dọc ở bên phải
    for (int i = 6; i < 30; i++)
    {
        Graphic::gotoxy(111, i);
        cout << char(186);
    }

    // Đường thẳng ở dưới
    Graphic::gotoxy(10, 30);
    cout << char(200);
    for (int i = 0; i < 100; i++)
    {
        Graphic::gotoxy(11 + i, 30);
        cout << char(205);
    }
    cout << char(188);

    // Đường dọc ở giữa
    Graphic::gotoxy(40, 5);
    cout << char(203);
    for (int i = 6; i < 30; i++)
    {
        Graphic::gotoxy(40, i);
        cout << char(186);
    }
    Graphic::gotoxy(40, 30);
    cout << char(202);

    // Đường thẳng nhỏ ở dưới góc trái
    Graphic::gotoxy(11, 28);
    for (int i = 0; i < 29; i++)
    {
        cout << char(205);
    }

    // Các viền góc
    Graphic::gotoxy(10, 7);
    cout << char(204);
    Graphic::gotoxy(40, 7);
    cout << char(206);
    Graphic::gotoxy(111, 7);
    cout << char(185);
    Graphic::gotoxy(10, 28);
    cout << char(204);
    Graphic::gotoxy(40, 28);
    cout << char(185);

    // In các hướng dẫn
    Graphic::gotoxy(43, 6);
    Graphic::setConsoleTextColor(text_Menu_Choice_Color);
    Graphic::setUTF8CodePage();
    cout << "ESC - TRỞ LẠI    F1 - ĐỌC TỪ    F2 - ĐỌC VÍ DỤ" << endl;
    Graphic::setDefaultCodePage();
}

short Dictionary::choice()
{
    short choose = 0;
    Graphic::setUTF8CodePage();

    string arrTitle[3] = {"TỪ ĐIỂN", "GIỚI THIỆU", "THOÁT CHƯƠNG TRÌNH"};
    short key;

    short width = 35, height = 3;
    short x = 42, y = 10;
    short padding = 5;

    Graphic::displayBackgroundColor();

    for (int i = 0; i < 3; i++)
    {
        Graphic::button(arrTitle[i], x, y + i * padding + 1, width, height, text_Button_Color, button_Color);
    }

    Graphic::button(arrTitle[choose], x, y + choose * padding + 1, width, height, text_Button_Choosen_Color, button_Choosen_Color);

    do
    {
        key = Graphic::getInputKey();
        switch (key)
        {
        case KEY_UP:
            if (choose > 0)
            {
                Graphic::button(arrTitle[choose], x, y + choose * padding + 1, width, height, text_Button_Color, button_Color);
                choose--;
                Graphic::button(arrTitle[choose], x, y + choose * padding + 1, width, height, text_Button_Choosen_Color, button_Choosen_Color);
            }
            else if (choose == 0)
            {
                Graphic::button(arrTitle[choose], x, y + choose * padding + 1, width, height, text_Button_Color, button_Color);
                choose = 2;
                Graphic::button(arrTitle[choose], x, y + choose * padding + 1, width, height, text_Button_Choosen_Color, button_Choosen_Color);
            }
            break;
        case KEY_DOWN:
            if (choose < 2)
            {
                Graphic::button(arrTitle[choose], x, y + choose * padding + 1, width, height, text_Button_Color, button_Color);
                choose++;
                Graphic::button(arrTitle[choose], x, y + choose * padding + 1, width, height, text_Button_Choosen_Color, button_Choosen_Color);
            }
            else if (choose == 2)
            {
                Graphic::button(arrTitle[choose], x, y + choose * padding + 1, width, height, text_Button_Color, button_Color);
                choose = 0;
                Graphic::button(arrTitle[choose], x, y + choose * padding + 1, width, height, text_Button_Choosen_Color, button_Choosen_Color);
            }
            break;
        }
        Sleep(TIME_DELAY);
    } while (key != KEY_ENTER);
    Graphic::setDefaultCodePage();

    Graphic::resetColor();
    return choose;
}

void Dictionary::createBox(short x, short y, short width, short height)
{
    Graphic::setConsoleTextColor(box_Color);
    // Đường thẳng ở trên
    Graphic::gotoxy(x, y - 1);
    cout << char(201);
    for (int i = 0; i < width; i++)
    {
        cout << char(205);
    }
    cout << char(187);

    // Đường dọc ở bên trái
    for (int i = y; i < height; i++)
    {
        Graphic::gotoxy(x, i);
        cout << char(186);
    }

    // Đường dọc ở bên phải
    for (int i = y; i < height; i++)
    {
        Graphic::gotoxy(x + width + 1, i);
        cout << char(186);
    }

    // Đường thẳng ở dưới
    Graphic::gotoxy(x, height);
    cout << char(200);
    for (int i = 0; i < width; i++)
    {
        Graphic::gotoxy(x + i + 1, height);
        cout << char(205);
    }
    cout << char(188);
}

int Dictionary::numbersOfPage()
{
    int wordsInList = wordTable.listKey()->size();
    int page = wordsInList / 20 + 1;
    return page;
}

void Dictionary::displayStatus(int currentWord, int currentPage)
{
    Graphic::gotoxy(13, 29);
    cout << "                         ";
    Graphic::gotoxy(13, 29);
    const short textColor[] = {255, 51, 0};
    Graphic::setConsoleTextColor(textColor);
    Graphic::setUTF8CodePage();
    cout << "\u001b[3m"
         << "Số từ: " << currentWord + 1 << "/" << wordTable.listKey()->size() << " - Trang: " << currentPage + 1 << "/" << numbersOfPage() << "\u001b[23m";
    Graphic::setDefaultCodePage();
}

void Dictionary::displayDetail(Word word, short x, short y)
{
    // Làm sạch tên, loại và nghĩa
    Graphic::gotoxy(x, y);
    cout << "                                                                 ";
    // Làm sạch ví dụ
    Graphic::gotoxy(x, y + 2);
    cout << "                                                                 ";
    // In ra chi tiết từ
    Graphic::gotoxy(x, y);
    Graphic::setConsoleTextColor(word_Selected_Color);
    cout << "\u001b[3m";
    cout << word.getName() << " (" << word.getType() << "): " << word.getMeaning();
    Graphic::gotoxy(x, y + 2);
    cout << "Ví dụ: " << word.getExample();
    cout << "\u001b[23m";
    Graphic::setConsoleTextColor(default_Text_Color);
}

void Dictionary::displayListKey(const int &current_Word, const int &current_Page, short x, short y)
{
    Node *current = wordTable.listKey()->getHead();
    int i = 0, count = 0;
    int wordIndex = current_Page * NUMBER_TO_VIEW + current_Word;
    // table.listKey()->quickSort(table.listKey(), 0, table.listKey()->size() - 1);
    // upperCaseFirstLetter(table);

    for (int i = 0; i < NUMBER_TO_VIEW; i++)
    {
        Graphic::gotoxy(x, y + i);
        cout << "                        ";
        // Graphic::gotoxy(x, y);
    }
    while (current != nullptr)
    {
        Word word = current->getData();
        Graphic::label(word.getName(), x, y + i, list_Key_Color);
        i++;
        count++;
        if (count % NUMBER_TO_VIEW == 0 && count / NUMBER_TO_VIEW == current_Page)
        {
            for (int i = 0; i < NUMBER_TO_VIEW; i++)
            {
                Graphic::gotoxy(x, y + i);
                cout << "                        ";
                // Graphic::gotoxy(x, y);
            }
            i = 0;
        }
        if (i == NUMBER_TO_VIEW)
            break;
        current = current->getNext();
    }
    cout << "\u001b[3m";
    Graphic::label(wordTable.listKey()->at(wordIndex).getName(), x, y + current_Word, word_Selected_Color);
    cout << "\u001b[23m";
}

void Dictionary::wordSelected(int indexKey)
{
    short x = 43;
    short y = 12;
    Graphic::setUTF8CodePage();
    displayDetail(wordTable.listKey()->at(indexKey), x, y);
    Graphic::setDefaultCodePage();
}

void textToSpeech(const string &text)
{
    string cmdlines = "TTSAPI.vbs \"" + text + "\"";
    system(cmdlines.c_str());
}


