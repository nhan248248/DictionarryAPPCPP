#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <string>
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
    Word(const string &name, const string &type, const string &meaning);
    string getName() const;
     string getType() const;
     string getMeaning() const;
     string getExample() const;
    void setName(const string& w);
    void setType(const string& t);
    void setMeaning(const string& m);
    void setExample(const string& e);

    friend ostream& operator << (ostream& out, const Word& word);
};

#endif
