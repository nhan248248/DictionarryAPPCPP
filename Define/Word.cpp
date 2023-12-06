#include "../Declare/Word.h"

// Định nghĩa phương thức constructor
Word::Word()
{
    this->name = "";
    this->type = "";
    this->meaning = "";
    this->example = "";
}

Word::Word(const string &name, const string &type, const string &meaning, const string &example)
{
    this->name = name;
    this->type = type;
    this->meaning = meaning;
    this->example = example;
}

Word::~Word(){}

string Word::getName() const
{
    return name;
}

string Word::getType() const
{
    return type;
}

string Word::getMeaning() const
{
    return meaning;
}

string Word::getExample() const
{
    return example;
}

void Word::setName(const string& n)
{
    this->name = n;
}

void Word::setType(const string& t)
{
    this->type = t;
}

void Word::setMeaning(const string& m)
{
    this->meaning = m;
}

void Word::setExample(const string& e)
{
    this->example = e;
}

istream& operator>>(istream& in, Word& word) {
    string line;
    getline(in, line);
    stringstream ss(line);
    getline(ss, word.name, '/');
    getline(ss, word.type, '/');
    getline(ss, word.meaning, '/');
    getline(ss, word.example);
    return in;
}

ostream &operator<<(ostream& out, const Word& word)
{
    out << word.name << "/" << word.type << "/" << word.meaning << "/" << word.example << endl;
    return out;
}

bool Word::operator==(const Word &other) const
{
    // So sánh các thành phần của hai đối tượng Word
    return (name == other.name && type == other.type && meaning == other.meaning && example == other.example);
}