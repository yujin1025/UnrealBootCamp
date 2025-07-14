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
		cout << title << "�뿩 �Ϸ�. ���� ���� : " << it->second << endl;
	}
	else {
		cout << "�뿩 �Ұ�" << endl;
	}
}

void BorrowManager::returnBook(const string& title)
{
	auto it = stock.find(title);
	if (it != stock.end() && it->second < 3) {
		it->second++;
		cout << title << " �ݳ� �Ϸ�. ���� ���� : " << it->second << endl;
	}
	else {
		cout << "�ݳ� �Ұ�" << endl;
	}
}

void BorrowManager::displayStock() const
{
	cout << "���� ���� ��� ��Ȳ:" << endl;
	for (auto& book : stock) {
		cout << "- " << book.first << " : " << book.second << "��" << endl;
	}
}
