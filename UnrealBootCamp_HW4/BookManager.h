#pragma once
#include <vector>
#include "Book.h"

class BookManager {
private:
	vector<Book> books;

public:
    void addBook(const string& title, const string& author);
    void displayAllBooks() const;
    Book* findBookByTitle(const string& title);
    Book* findBookByAuthor(const string& author);
};