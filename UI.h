#ifndef UI_H
#define UI_H

#include <iostream>
using namespace std;


class UI
{
    public:
        static void menu();
};

void UI::menu()
{
    cout << "-----------------DICTIONARY APP------------------\n";
    cout << "Enter your choice, enter 0 to exit..." << endl;
    cout << "1. Add word" << endl;
    cout << "2. Delete word" << endl;
    cout << "3. Search word" << endl;
    cout << "4. Update word" << endl;
    cout << "5. Clear" << endl;
}

#endif