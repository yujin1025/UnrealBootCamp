#include "BookManager.h"
#include <iostream>

using namespace std;

// å �߰� 
void BookManager::addBook(const string& title, const string& author)
{
	books.push_back(Book(title, author)); 
	cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
}

// ��� å ���
void BookManager::displayAllBooks() const
{
    if (books.empty()) {
        cout << "���� ��ϵ� å�� �����ϴ�." << endl;
        return;
    }

    cout << "���� ���� ���:" << endl;
    for (auto& book : books) { 
        cout << "- " << book.getTitle() << " by " << book.getAuthor() << endl;
    }
}

// å �������� �˻�
Book* BookManager::findBookByTitle(const string& title)
{
    for (auto& book : books) {
        if (book.getTitle() == title)
            return &book;
    }
    return nullptr;
}

// å �۰��� �˻�
Book* BookManager::findBookByAuthor(const string& author)
{
    for (auto& book : books) {
        if (book.getAuthor() == author)
            return &book;
    }
    return nullptr;
}
