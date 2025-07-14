#include <iostream>
#include "BookManager.h"
#include "BorrowManager.h"

int main() {
    BookManager bookManager;
    BorrowManager borrowManager;
    string title, author;

    cout << "\n������ ���� ���α׷�" << endl;
    cout << "1. å �߰�" << endl;
    cout << "2. ��� å ���" << endl;
    cout << "3. �������� å �˻�" << endl;
    cout << "4. �۰��� å �˻�" << endl;
    cout << "5. å �뿩" << endl;
    cout << "6. å �ݳ�" << endl;
    cout << "7. ��� ��Ȳ Ȯ��" << endl;
    cout << "8. ����" << endl;

    while (true) {
        cout << "����: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            cout << "å ����: ";
            getline(cin, title);
            cout << "å ����: ";
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
            cout << "�˻��� å ����: ";
            getline(cin, title);
            auto book = bookManager.findBookByTitle(title);
            if (book) {
                cout << "�˻� ���: " << book->getTitle() << " by " << book->getAuthor() << endl;
            }
            else {
                cout << "å�� ã�� �� �����ϴ�." << endl;
            }
            break;
        }
        case 4: {
            cout << "�˻��� �۰� �̸�: ";
            getline(cin, author);
            auto book = bookManager.findBookByAuthor(author);
            if (book) {
                cout << "�˻� ���: " << book->getTitle() << " by " << book->getAuthor() << endl;
            }
            else {
                cout << "å�� ã�� �� �����ϴ�." << endl;
            }
            break;
        }
        case 5:
            cout << "�뿩�� å ����: ";
            getline(cin, title);
            borrowManager.borrowBook(title);
            break;
        case 6:
            cout << "�ݳ��� å ����: ";
            getline(cin, title);
            borrowManager.returnBook(title);
            break;
        case 7:
            borrowManager.displayStock();
            break;
        case 8:
            cout << "���α׷��� �����մϴ�." << endl;
            return 0;
        default:
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0;
}