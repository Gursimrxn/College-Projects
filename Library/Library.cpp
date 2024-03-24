#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    string ISBN;
    string title;
};

class Library {
private:
    vector<Book> books;

public:
    Library() {
        books.push_back({"0321714114", "C++"});
        books.push_back({"0131103627", "C Programming"});
        books.push_back({"0321623218", "Effective C++"});
        books.push_back({"0321958310", "Clean Code"});
        books.push_back({"1449331818", "Python"});
        books.push_back({"1118013847", "Java"});
        books.push_back({"1492057889", "Python Crash Course"});
        books.push_back({"1593275846", "Automate with Python"});
    }

    void findBook(const string& isbn) {
        bool found = false;
        string title;
        for (const auto& book : books) {
            if (book.ISBN == isbn) {
                title = book.title;
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Book found in the library:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "ISBN: " << isbn << endl;
            cout << "Title: " << title << endl;
            cout << "----------------------------------------" << endl;
        } else {
            cout << "Book with ISBN " << isbn << " not found in the library." << endl;
        }
    }
};

int main() {
    Library library;

    string isbn;
    cout << "Enter the ISBN of the book to find: ";
    cin >> isbn;

    library.findBook(isbn);

    return 0;
}
