#pragma once
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book(const string& title, const string& author);
    string getTitle() const;
    string getAuthor() const;
};