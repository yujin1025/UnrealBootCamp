#include "BorrowManager.h"
#include <iostream>

using namespace std;

void BorrowManager::initializeStock(Book* book, int quantity)
{
	stock[book->getTitle()] = quantity;
}

void BorrowManager::borrowBook(const string& title)
{
	auto it = stock.find(title);
	if (it != stock.end() && it->second > 0) {
		it->second--;
		cout << title << "대여 완료. 남은 수량 : " << it->second << endl;
	}
	else {
		cout << "대여 불가" << endl;
	}
}

void BorrowManager::returnBook(const string& title)
{
	auto it = stock.find(title);
	if (it != stock.end() && it->second < 3) {
		it->second++;
		cout << title << " 반납 완료. 현재 수량 : " << it->second << endl;
	}
	else {
		cout << "반납 불가" << endl;
	}
}

void BorrowManager::displayStock() const
{
	cout << "현재 도서 재고 현황:" << endl;
	for (auto& book : stock) {
		cout << "- " << book.first << " : " << book.second << "권" << endl;
	}
}
