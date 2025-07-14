#include "BookManager.h"
#include <iostream>

using namespace std;

// 책 추가 
void BookManager::addBook(const string& title, const string& author)
{
	books.push_back(Book(title, author)); 
	cout << "책이 추가되었습니다: " << title << " by " << author << endl;
}

// 모든 책 출력
void BookManager::displayAllBooks() const
{
    if (books.empty()) {
        cout << "현재 등록된 책이 없습니다." << endl;
        return;
    }

    cout << "현재 도서 목록:" << endl;
    for (auto& book : books) { 
        cout << "- " << book.getTitle() << " by " << book.getAuthor() << endl;
    }
}

// 책 제목으로 검색
Book* BookManager::findBookByTitle(const string& title)
{
    for (auto& book : books) {
        if (book.getTitle() == title)
            return &book;
    }
    return nullptr;
}

// 책 작가로 검색
Book* BookManager::findBookByAuthor(const string& author)
{
    for (auto& book : books) {
        if (book.getAuthor() == author)
            return &book;
    }
    return nullptr;
}
