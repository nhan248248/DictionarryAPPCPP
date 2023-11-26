#include "../Declare/Dictionary.h"

Dictionary::Dictionary()
{
    wordTable.insert(Word("Hi", "Động từ", "Xin chào", "Hi, I am Nhàn"));
    wordTable.insert(Word("Computer", "Danh từ", "Máy tính", "I work with a computer."));
    wordTable.insert(Word("Programming", "Danh từ", "Lập trình", "I enjoy programming."));
    wordTable.insert(Word("Mountain", "Danh từ", "Núi", "They climbed the mountain."));
    wordTable.insert(Word("Ocean", "Danh từ", "Đại dương", "The ocean is vast."));
    wordTable.insert(Word("Adventure", "Danh từ", "Cuộc phiêu lưu", "They had an exciting adventure."));
    wordTable.insert(Word("Listen", "Động từ", "Nghe", "Listen carefully to the music."));
    wordTable.insert(Word("Garden", "Danh từ", "Vườn", "She planted flowers in the garden."));
    wordTable.insert(Word("Incredible", "Tính từ", "Không thể tin được", "The view was incredible."));
    wordTable.insert(Word("Apple", "Danh từ", "Quả táo", "i have an apple."));
    wordTable.insert(Word("Work", "Động từ", "Làm việc", "i am working."));
    wordTable.insert(Word("Word", "Danh từ", "Từ", "i am writing some words."));
    wordTable.insert(Word("Run", "Động từ", "Chạy", "I am running on the road."));
    wordTable.insert(Word("Cute", "Tính từ", "Dễ thương", "You are so cute!."));
    
    mainMenu();
}
Dictionary::~Dictionary()
{

}

void Dictionary::checkBug(){
    gotoxy(0, 0);
    cout << "Lỗi ở đây" << endl;
    system("pause");
}

void Dictionary::mainMenu(){
    int choose = choice();
    if(choose == TU_DIEN){
        clscr();
        dictionaryMenu();
    }
    else if(choose == GIOI_THIEU){
        resetBackgroundColor();
        system("cls");
        introduction();
    }
    else{
        exit(0);
    }
}

void Dictionary::introduction(){
    int x = 50, y = 2;
    int choose;
    gotoxy(x, y - 1);
    do
    {
        clscr();
        setUTF8CodePage();
        cout << "TỪ ĐIỂN ANH VIỆT";
        gotoxy(x - 18, y + 1);
        cout << "===========================================================";
        gotoxy(x - 18, y + 3);
        cout << "Tác giả: ";
        gotoxy(x - 18, y + 4);
        cout << "LÊ VĂN NHÀN";
        gotoxy(x - 18, y + 5);
        cout << "NGUYỄN THỊ NGÂN ANH" << endl;

        cout << "\t\t\t\tNội dung" << endl;
        cout << "\t\t\t\tNội dung" << endl;

        gotoxy(x - 3, y + 30);
        cout << "Nhấn phím ESC để quay trở lại....";
        setDefaultCodePage();
        choose = getInputKey();
        Sleep(TIME_DELAY);
    } while (choose != KEY_EXIT);
    clscr();
    mainMenu();
}

void Dictionary::dictionaryMenu()
{
    int choose;
    int index = 0;
    int x = 15, y = 7;
    const int size = 10;
    do
    {
        mainBox();
        displayListKey(index, size, x, y);
        displayNumberOfWord();
        wordSelected(index);
        choose = getInputKey();

        if(choose == KEY_UP){
            if(index > 0){
                index--;
            }
            else if(index == 0){
                index = size - 1;
            }
        }
        else if(choose == KEY_DOWN){
            if(index < size - 1){
                index++;
            }
            else if(index == size - 1){
                index = 0;
            }
        }
        else if(choose == KEY_ADD){
            clscr();
            addWord();
            clscr();
        }
        else if (choose == KEY_UPDATE){
            clscr();
            update();
            clscr();
        }
        else if (choose == KEY_DELETE){
            clscr();
            deleteWord();
            clscr();
        }
        else if (choose == KEY_SEARCH){
            clscr();
            search();
            clscr();
        }
        else if(choose == KEY_SPEAK_WORD){
            string text = wordTable.listKey()->at(index).getName();
            speak(text);
            continue;
        }
        else if(choose == KEY_SPEAK_EXAMPLE){
            string text = wordTable.listKey()->at(index).getExample();
            speak(text);
            continue;
        }
        Sleep(TIME_DELAY);
    } while (choose != KEY_EXIT);
    mainMenu();
}
//1. Chức năng thêm từ
void Dictionary::addWord()
{
    Word word;
    string s;
    createBox(40, 10, 40, 16);

    setConsoleTextColor(3);
    setUTF8CodePage();
    // Nhập tên từ
    do {
        gotoxy(42, 11);
        cout << "Tên từ: ";
        fflush(stdin);
        getline(cin, s);
    } while (s.empty());
    word.setName(s);

    // Nhập loại từ
    do {
        gotoxy(42, 12);
        cout << "Loại từ: ";
        fflush(stdin);
        getline(cin, s);
    } while (s.empty());
    word.setType(s);

    // Nhập nghĩa
    do {
        gotoxy(42, 13);
        cout << "Nghĩa: ";
        fflush(stdin);
        getline(cin, s);
    } while (s.empty());
    word.setMeaning(s);

    // Nhập ví dụ
    do {
        gotoxy(42, 14);
        cout << "Ví dụ: ";
        fflush(stdin);
        getline(cin, s);
    } while (s.empty());
    word.setExample(s);
    //checkBug();
    wordTable.insert(word);
    showMessageBox("Thêm từ thành công!", "Thông báo", 0);
    setDefaultCodePage();
}
//2. Chức năng sửa
void Dictionary::update(){
    createBox(40, 10, 40, 16);

    setUTF8CodePage();
    gotoxy(50, 2);
    
    cout << "Sửa từ ở đây";

    showMessageBox("Đã sửa", "Thông báo", 0);
    setDefaultCodePage();
}
//3. Chức năng Xóa
void Dictionary::deleteWord(){
    setUTF8CodePage();

    cout << "Hành động xoá";
    
    showMessageBox("Đã xóa", "Thông báo", utf8CodePage);
    setDefaultCodePage();
}
//4. Chức năng tìm kiếm

//Hàm kiểm trả về danh sách từ chứa chuỗi được nhập vào
DoublyLinkedList Dictionary::searchInList(const string& query, DoublyLinkedList* dataList) {
    DoublyLinkedList results;

    // Chuyển đổi query thành chữ thường để tìm kiếm không phân biệt chữ hoa thường
    string lowercaseQuery = query;
    transform(lowercaseQuery.begin(), lowercaseQuery.end(), lowercaseQuery.begin(), ::tolower);

    Node* current = dataList->head;

    while (current != nullptr) {
        const auto& item = current->data;
        // Chuyển đổi tên từ thành chữ thường để so sánh
        string lowercaseName = item.getName();
        transform(lowercaseName.begin(), lowercaseName.end(), lowercaseName.begin(), ::tolower);

        if (lowercaseName.find(lowercaseQuery) != string::npos) {
            results.append(item);
        }
        current = current->next;
    }

    return results;
}

bool Dictionary::isExit(const string& query, DoublyLinkedList* list){
    string lowercaseQuery = query;
    transform(lowercaseQuery.begin(), lowercaseQuery.end(), lowercaseQuery.begin(), ::tolower);

    Node* current = list->head;
    bool check = false;

    while (current != nullptr) {
        const auto& item = current->data;
        // Chuyển đổi tên từ thành chữ thường để so sánh
        string lowercaseName = item.getName();
        transform(lowercaseName.begin(), lowercaseName.end(), lowercaseName.begin(), ::tolower);

        if (lowercaseName == lowercaseQuery) {
            check = true;
            break; // Nếu tìm thấy khớp, thoát vòng lặp ngay lập tức
        }
        current = current->next;
    }
    return check;
}


//Hàm tìm từ và hiển thị danh sách từ chứa ký tự được nhập
void Dictionary::search(){
    //Vị trí nhập
    int x_Input = 12, y_Input = 6;
    // Vị trí xuất danh sách
    int x_List = 15, y_List = 9;
    // Vị trí xuất chi tiết từ
    int x_Detail = 43, y_Detail = 9;
    //Vị trí con trỏ nhập
    int x_Point = 6;

    displayNumberOfWord();

    char key;
    string userInput = "";

    //getchar();
    searchBox();

    setUTF8CodePage();
    for(int i = 0; i < 10; i++){
        label(wordTable.listKey()->at(i).getName(), x_List, y_List + i, DEFAULT_TEXT_COLOR);
    }
    
    gotoxy(x_Input, y_Input);
    cout << "Nhập: ";
    setDefaultCodePage();
    
    do{
        
        gotoxy(x_Input + x_Point, y_Input);
        fflush(stdin);
        key = _getch();
        
        //Xóa từng ký tự trong chuỗi vừa nhập
        if(key == '\b'){
            if(!userInput.empty()){
                x_Point--;
                userInput.pop_back();
            }
        }

        if(isalpha(key)){
            userInput += key;
            x_Point++;
        }

        DoublyLinkedList searchResults = searchInList(userInput, wordTable.listKey());
        if(key == 9){
            string text = searchResults.at(0).getName();
            speak(text);
            continue;
        }
        else if(key == 17){
            string text = searchResults.at(0).getExample();
            speak(text);
            continue;
        }
        
        //Làm sạch chỗ nhập và hiển thị chuỗi vừa nhập
        gotoxy(x_Input + 6, y_Input);
        cout << "                  ";
        gotoxy(x_Input + 6, y_Input);
        setConsoleTextColor(220);
        cout << userInput;
        setConsoleTextColor(DEFAULT_TEXT_COLOR);

        //Làm sạch danh sách
        for(int i = 0; i < 10; i++){
                gotoxy(x_List, y_List + i);
                cout << "               ";
        }

        setUTF8CodePage();

        //Kiểm tra từ vừa nhập có trong danh sách không
        if(!isExit(userInput, wordTable.listKey())){
            if(searchResults.size() != 1){
                gotoxy(x_Detail, y_Detail);
                cout << "                                                           ";
                gotoxy(x_Detail, y_Detail + 2);
                cout << "                                                           ";

                gotoxy(x_Detail, y_Detail);
                setConsoleTextColor(1);
                cout << "Không tìm thấy!!!";
            }
            else if(searchResults.size() == 1){
                displayDetail(searchResults.at(0), x_Detail, y_Detail);
            }
        }
        else{
            displayDetail(searchResults.at(0), x_Detail, y_Detail);
        }

        //Chưa nhập gì thì không hiển thị gì cả
        if(x_Point == 6){
            gotoxy(x_Detail, y_Detail);
            cout << "                                                           ";
            gotoxy(x_Detail, y_Detail + 2);
            cout << "                                                           ";
        }

        //Hiển thị danh sách từ có chứa chuỗi vừa nhập
        for(int i = 0; i < searchResults.size(); i++){
            if(i == 10) break;
            label(searchResults.at(i).getName(), x_List, y_List + i, DEFAULT_TEXT_COLOR);
        }
        setDefaultCodePage();
        //Sleep(TIME_DELAY);
    }
    while (key != 27);
}

//Định nghĩa hàm phát âm
void Dictionary::speak(const string& text){
    string cmdlines = ".\\Common\\TTSAPI.vbs \"" + text + "\"";
    system(cmdlines.c_str());
}

// UI
void Dictionary::gotoxy(short x, short y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Dictionary::clscr(){
    system("cls");
}


// XỬ LÝ GIAO DIỆN
void Dictionary::mainBox()
{
    gotoxy(50, 2);
    setUTF8CodePage();
    cout << "TỪ ĐIỂN ANH VIỆT";
    setTitle("DICTIONARY APPLICATION");
    
    setDefaultCodePage();
    setConsoleTextColor(DEFAULT_TEXT_COLOR);
    //Đường thẳng ở trên
    gotoxy(10, 5);
    cout << char(201);
    for(int i = 0; i < 100; i++){
        cout << char(205);
    }
    cout << char(187);

    //Đường thẳng ở giữa
    gotoxy(40, 10);
    for(int i = 0; i < 72; i++){
        cout << char(205);
    }

    //Đường dọc ở bên trái
    for(int i = 6; i < 30; i++){
        gotoxy(10, i);
        cout << char(186);
    }

    //Đường dọc ở bên phải
    for(int i = 6; i < 30; i++){
        gotoxy(111, i);
        cout << char(186);
    }

    //Đường thẳng ở dưới
    gotoxy(10, 30);
    cout << char(200);
    for(int i = 0; i < 100; i++){
        gotoxy(11+i, 30);
        cout << char(205);
    }
    cout << char(188);

    //Đường dọc ở giữa
    gotoxy(40, 5);
    cout << char(203);
    for(int i = 6; i < 30; i++){
        gotoxy(40, i);
        cout << char(186);
    }
    gotoxy(40, 30);
    cout << char(202);
    
    // Các viền góc
    gotoxy(40, 10);
    cout << char(204);
    gotoxy(111, 10);
    cout << char(185);

    //In các hướng dẫn
    gotoxy(44, 6);
    setConsoleTextColor(12);
    setUTF8CodePage();
    cout << "ALT - THÊM\t\t   SPACE - SỬA\t\t     F1 - ĐỌC" << endl;
    gotoxy(44, 9);
    cout << "DELETE - XOÁ\t   SHIFT - TÌM KIẾM\t     ESC - TRỞ LẠI" << endl;
    setConsoleTextColor(DEFAULT_TEXT_COLOR);
    setDefaultCodePage();
}

void Dictionary::searchBox()
{
    gotoxy(50, 2);
    setUTF8CodePage();
    cout << "TỪ ĐIỂN ANH VIỆT";
    
    setDefaultCodePage();
    setConsoleTextColor(DEFAULT_TEXT_COLOR);
    //Đường thẳng ở trên
    gotoxy(10, 5);
    cout << char(201);
    for(int i = 0; i < 100; i++){
        cout << char(205);
    }
    cout << char(187);

    //Đường thẳng ở giữa
    gotoxy(11, 7);
    for(int i = 0; i < 100; i++){
        cout << char(205);
    }

    //Đường dọc ở bên trái
    for(int i = 6; i < 30; i++){
        gotoxy(10, i);
        cout << char(186);
    }

    //Đường dọc ở bên phải
    for(int i = 6; i < 30; i++){
        gotoxy(111, i);
        cout << char(186);
    }

    //Đường thẳng ở dưới
    gotoxy(10, 30);
    cout << char(200);
    for(int i = 0; i < 100; i++){
        gotoxy(11+i, 30);
        cout << char(205);
    }
    cout << char(188);

    //Đường dọc ở giữa
    gotoxy(40, 5);
    cout << char(203);
    for(int i = 6; i < 30; i++){
        gotoxy(40, i);
        cout << char(186);
    }
    gotoxy(40, 30);
    cout << char(202);
    
    // Các viền góc
    gotoxy(10, 7);
    cout << char(204);
    gotoxy(40, 7);
    cout << char(206);
    gotoxy(111, 7);
    cout << char(185);

    //In các hướng dẫn
    gotoxy(43, 6);
    setConsoleTextColor(12);
    setUTF8CodePage();
    cout << "ESC - TRỞ LẠI    F1 - ĐỌC TỪ    F2 - ĐỌC VÍ DỤ" << endl;
    setDefaultCodePage();
}

int Dictionary::choice(){
	int choose = 0;
    setUTF8CodePage();
    string arrTitle[3] = {"TỪ ĐIỂN", "GIỚI THIỆU", "THOÁT   "};
	int key;
	
    int width = 35;
    int height = 3;
    int x = 40;
    int y = 10;
    int text = 0, textSelected = 124, background = 220 , backgroundSelected = 190;
    int padding = 4;
    //setConsoleTextColor(31);

    for(int i = 0; i < 3; i++){
        button(arrTitle[i], x, y + i*padding + 1, width, height, text, background);
    }

    button(arrTitle[choose], x, y + choose*padding + 1, width, height, textSelected, backgroundSelected);

    do{
        key = getInputKey();
        switch (key)
        {
        case KEY_UP:
            if(choose > 0){
                button(arrTitle[choose], x, y + choose*padding + 1, width, height, text, background);
                choose--;
                button(arrTitle[choose], x, y + choose*padding + 1, width, height, textSelected, backgroundSelected);
            }
            else if(choose == 0){
                button(arrTitle[choose], x, y + choose*padding + 1, width, height, text, background);
                choose = 2;
                button(arrTitle[choose], x, y + choose*padding + 1, width, height, textSelected, backgroundSelected);
            }
            break;
        case KEY_DOWN:
            if(choose < 2){
                button(arrTitle[choose], x, y + choose*padding + 1, width, height, text, background);
                choose++;
                button(arrTitle[choose], x, y + choose*padding + 1, width, height, textSelected, backgroundSelected);
            }
            else if(choose == 2){
                button(arrTitle[choose], x, y + choose*padding + 1, width, height, text, background);
                choose = 0;
                button(arrTitle[choose], x, y + choose*padding + 1, width, height, textSelected, backgroundSelected);
            }
            break;
        }
        Sleep(TIME_DELAY);
    }while(key != KEY_ENTER);
    setDefaultCodePage();
    resetBackgroundColor();
    return choose;
}

void Dictionary::createBox(int x, int y, int width, int height){
    
    clscr();
    setConsoleTextColor(DEFAULT_TEXT_COLOR);
    //Đường thẳng ở trên
    gotoxy(x, y - 1);
    cout << char(201);
    for(int i = 0; i < width; i++){
        cout << char(205);
    }
    cout << char(187);

    //Đường dọc ở bên trái
    for(int i = y; i < height; i++){
        gotoxy(x, i);
        cout << char(186);
    }

    //Đường dọc ở bên phải
    for(int i = y; i < height; i++){
        gotoxy(x + width + 1 , i);
        cout << char(186);
    }

    //Đường thẳng ở dưới
    gotoxy(x, height);
    cout << char(200);
    for(int i = 0; i < width; i++){
        gotoxy(x + i + 1, height);
        cout << char(205);
    }
    cout << char(188);
}

//Đổi màu chữ
void Dictionary::setConsoleTextColor(int textColor) {
    cout << "\033[38;5;" << textColor << "m";
}

void Dictionary::setBackgroundColor(int color) {
    // Sử dụng mã màu và chuỗi escape ANSI để đặt màu nền
    cout << "\033[48;5;" << color << "m";
}

void Dictionary::resetBackgroundColor() {
    cout << "\033[0m"; // Đặt mã màu về mặc định
}

void Dictionary::button(string title, int x, int y, int width, int height, int textColor, int backgroundColor){
    setBackgroundColor(backgroundColor);
    int midPos = x + 3 + (width - title.length())/2;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            gotoxy(x + j, y);
            cout << "  "; 
        }
        y++;
        cout << "\n";
    }
    gotoxy(midPos , y - (height + 1)/2);
    setConsoleTextColor(textColor);
    cout << title;
}

void Dictionary::label(const string& title, int x, int y, int color) {

    // Đảm bảo rằng x và y không vượt quá giới hạn của màn hình
    if (x >= 0 && y >= 0 && x < SCREEN_WIDTH && y < SCREEN_HEIGHT) {
        gotoxy(x, y);
        setConsoleTextColor(color);
        // In ra màn hình không vượt quá giới hạn
        cout << title.substr(0, SCREEN_WIDTH - x);
    }
}

void Dictionary::upperCaseFirstLetter(HashTable table){
    
    Node *current = table.listKey()->head;
    while(current != nullptr){
        Word word = current->data;
        current->data.getName()[0] = toupper(current->data.getName()[0]);
        current->data.getMeaning()[0] = toupper(current->data.getMeaning()[0]);
        current = current->next;
    }
}

void Dictionary::displayNumberOfWord(){
    gotoxy(13, 29);
    setConsoleTextColor(1);
    //setBackgroundColor(124);
    setUTF8CodePage();
    cout << "\u001b[3m" << "Số từ trong DS:   " << wordTable.listKey()->size() << "\u001b[0m";
    //setBackgroundColor(0);
    setDefaultCodePage();
}

void Dictionary::displayDetail(Word word, int x, int y){
    
    //Làm sạch tên, loại và nghĩa
    gotoxy(x, y);
    resetBackgroundColor();
    cout << "                                                                 ";
    //Làm sạch ví dụ
    gotoxy(x, y + 2);
    cout << "                                                                 ";
    // In ra chi tiết từ
    gotoxy(x, y);
    setConsoleTextColor(220);
    cout << word.getName() << " (" << word.getType() << "): " << word.getMeaning();
    gotoxy(x, y + 2);
    cout << "Ví dụ: " << word.getExample();
    setConsoleTextColor(DEFAULT_TEXT_COLOR);
}

void Dictionary::displayListKey(int start, int end, int x, int y){
    Node *current = wordTable.listKey()->head;
    int i = 0;
    // table.listKey()->quickSort(table.listKey(), 0, table.listKey()->size() - 1);
    // upperCaseFirstLetter(table);
    int index = start;

    while(current != nullptr){
        Word word = current->data;
        label(word.getName(), x, y + i, DEFAULT_TEXT_COLOR);
        i++;
        if(i == end) break;
        current = current->next;
    }
    label(wordTable.listKey()->at(index).getName(), x, y + index, WORD_SELECTED_COLOR);
}

void Dictionary::wordSelected(int indexKey){
    int x = 43;
    int y = 12;
    setUTF8CodePage();
    displayDetail(wordTable.listKey()->at(indexKey), x, y);
    setDefaultCodePage();
}

void textToSpeech(const string& text) {
    string cmdlines = "TTSAPI.vbs \"" + text + "\"";
    system(cmdlines.c_str());
}

//Đổi tiêu đề console
void Dictionary::setTitle(const char *title)
{
	SetConsoleTitleA(title);
}

//Đặt codePage thành UTF8
void Dictionary::setUTF8CodePage(){
    system("MODE CON: CP SELECT=65001 > nul");
}

//Trả codePage về mặc định
void Dictionary::setDefaultCodePage(){
    SetConsoleOutputCP(defaultCodePage);
}

//Đưa ra thông báo 
int Dictionary::showMessageBox(const char *message, const char *caption, UINT type)
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


KEY Dictionary::getInputKey()
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



