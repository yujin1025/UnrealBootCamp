#include <iostream>
#include "BookManager.h"
#include "BorrowManager.h"

int main() {
    BookManager bookManager;
    BorrowManager borrowManager;
    string title, author;

    cout << "\n도서관 관리 프로그램" << endl;
    cout << "1. 책 추가" << endl;
    cout << "2. 모든 책 출력" << endl;
    cout << "3. 제목으로 책 검색" << endl;
    cout << "4. 작가로 책 검색" << endl;
    cout << "5. 책 대여" << endl;
    cout << "6. 책 반납" << endl;
    cout << "7. 재고 현황 확인" << endl;
    cout << "8. 종료" << endl;

    while (true) {
        cout << "선택: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            cout << "책 제목: ";
            getline(cin, title);
            cout << "책 저자: ";
            getline(cin, author);
            bookManager.addBook(title, author);
            auto book = bookManager.findBookByTitle(title);
            if (book) {
                borrowManager.initializeStock(book);
            }
            break;
        }
        case 2:
            bookManager.displayAllBooks();
            break;
        case 3: {
            cout << "검색할 책 제목: ";
            getline(cin, title);
            auto book = bookManager.findBookByTitle(title);
            if (book) {
                cout << "검색 결과: " << book->getTitle() << " by " << book->getAuthor() << endl;
            }
            else {
                cout << "책을 찾을 수 없습니다." << endl;
            }
            break;
        }
        case 4: {
            cout << "검색할 작가 이름: ";
            getline(cin, author);
            auto book = bookManager.findBookByAuthor(author);
            if (book) {
                cout << "검색 결과: " << book->getTitle() << " by " << book->getAuthor() << endl;
            }
            else {
                cout << "책을 찾을 수 없습니다." << endl;
            }
            break;
        }
        case 5:
            cout << "대여할 책 제목: ";
            getline(cin, title);
            borrowManager.borrowBook(title);
            break;
        case 6:
            cout << "반납할 책 제목: ";
            getline(cin, title);
            borrowManager.returnBook(title);
            break;
        case 7:
            borrowManager.displayStock();
            break;
        case 8:
            cout << "프로그램을 종료합니다." << endl;
            return 0;
        default:
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}