#include "Dictionary.h"

Dictionary::Dictionary()
{
    mainMenu();
}
Dictionary::~Dictionary()
{

}

void Dictionary::addWord()
{
    Word word;
    string s = "";
    bool isRightInput = true;// kiểm tra chuỗi nhập vào

    //Nhập tên của từ
    cin.ignore();
    while (true) {
        cout <<"Ten tu: "; fflush(stdin); getline(cin, s);
        if(s == "")
        {
            cout << " " << "Loi!!Ban chua nhap ten tu" << endl;
            continue;
        }
        else
        {
            for (char c : s) {
                if (!isalpha(c)) {
                    isRightInput = false;  // Từ chứa ký tự đặc biệt hoặc số
                }
            }
        
            if(isRightInput == false)
            {
                isRightInput = true;
                cout << "Ky tu ban vua nhap khong hop le!!! Vui long nhap lai." << endl;
                continue;
            }
            else
            {
                word.setName(s);
                break;
            }
        }
    }

    //Nhập loại từ: Động từ, danh từ, tính từ, trạng từ, đại từ, giới từ, liên từ, thán từ
    while (true) {
        //Cách 1: để nhập loại từ
        // int choose;
        // string type[7] = {"Dong tu", "Danh tu", "Tinh tu"
        //                 ,"Trang tu", "Gioi tu", "Lien tu"
        //                 , "Than tu"};
        // cout << "1. Dong tu\t2. Danh tu\t3. Tinh tu\t4. Trang tu\t5.Gioi tu\n
        //          6. Lien tu\t7. Than tu\n";
        // cout << "Moi ban chon loai tu: "; cin >> choose;
        // if choose = 1 thi w.setType(type[0]);
        
        // Cách 2
        cout << "Loai tu: "; fflush(stdin); getline(cin, s);
        if(s == "")
        {
            cout << "Loi!!! Ban chua nhap loai tu." << endl;
            continue;
        }
        else
        {
            for (char c : s) {
                if (!isalpha(c) && c!= ' ') {
                    isRightInput = false;  // Từ chứa ký tự đặc biệt hoặc số
                }
            }
        
            if(isRightInput == false)
            {
                isRightInput = true;
                cout << "Ky tu ban vua nhap khong hop le!!! Vui long nhap lai." << endl;
                continue;
            }
            else
            {
                word.setType(s);
                break;
            }
        }
    }

    //Nhập nghĩa
    while (true) {
        cout << "Nghia: "; fflush(stdin); getline(cin, s);
        if(s == "")
        {
            cout << "Ban chua nhap nghia vui long nhap lai" << endl;
            continue;
        }
        else
        {
            word.setMeaning(s);
            break;
        }
    }

    //Nhập ví dụ
    while (true) {
        cout << "Vi du: "; fflush(stdin); getline(cin, s);
        if(s == "")
        {
            cout << "Ban chua nhap vi du vui long nhap lai" << endl;
            continue;
        }
        else
        {
            word.setExample(s);
            break;
        }
    }

    wordTable.insert(word);
    cout << "Them tu thanh cong" << endl;
}

void Dictionary::mainMenu()
{
    int choose;
    do
    {
        cout << "--------------------------"<< endl;
        cout << "0. Thoat" << endl;
        cout << "1. Them tu moi" << endl;
        cout << "2. Xoa tu" << endl;
        cout << "3. Tim kiem" << endl;
        cout << "4. Chinh sua" << endl;
        cout << "5. Hien thi danh sach tu" << endl;
        cout << "6. Xoa man hinh" << endl;
        cout << "--------------------------"<< endl;
        cout << "Nhap lua chon: "; cin >> choose;
        cout << "--------------------------"<< endl;
        switch (choose)
        {
        case 1:
            addWord();
            break;
        case 5:
            system("cls");
            wordTable.display();
            break;
        case 6:
            system("cls");
            break;
        default:
            break;
        }
    } while (choose != 0);
    
}
//1. Chức năng thêm từ
//2. Chức năng xóa từ
//3. Chức năng Tìm kiếm
//4. Chức năng sửa từ