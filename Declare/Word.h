#pragma once
#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <windows.h>
#include <string.h>
#include <algorithm>
#include <conio.h>
#include <ctype.h>
using namespace std;

class Word
{
private:
    string name;
    string type;
    string meaning;
    string example;

public:
    Word();
    Word(const string &name, const string &type, const string &meaning, const string &example);
    string getName() const;
    string getType() const;
    string getMeaning() const;
    string getExample() const;
    void setName(const string& w);
    void setType(const string& t);
    void setMeaning(const string& m);
    void setExample(const string& e);

    // friend ostream& operator << (ostream& out, const Word& word);
};

#endif
