#pragma once
#include <unordered_map>
#include "Book.h"

using namespace std;

class BorrowManager{
private:
	unordered_map<string, int> stock;

public:
    void initializeStock(Book* book, int quantity = 3);
    void borrowBook(const string& title);
    void returnBook(const string& title);
    void displayStock() const;
};