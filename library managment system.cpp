#include <iostream>
#include <vector>
using namespace std;

// Book Class
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        isIssued = false;
    }
};

// Member Class
class Member {
public:
    int memberId;
    string name;

    Member(int id, string n) {
        memberId = id;
        name = n;
    }
};

// Library Class
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:

    // Add Book
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        cout << "Book added successfully!\n";
    }

    // Add Member
    void addMember() {
        int id;
        string name;

        cout << "Enter Member ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, name);

        members.push_back(Member(id, name));

        cout << "Member added successfully!\n";
    }

    // Display Books
    void displayBooks() {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }

        cout << "\n===== BOOK LIST =====\n";

        for (auto &book : books) {
            cout << "ID: " << book.id << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Status: ";

            if (book.isIssued)
                cout << "Issued\n";
            else
                cout << "Available\n";

            cout << "----------------------\n";
        }
    }

    // Issue Book
    void issueBook() {
        int id;

        cout << "Enter Book ID to issue: ";
        cin >> id;

        for (auto &book : books) {
            if (book.id == id) {

                if (book.isIssued) {
                    cout << "Book is already issued.\n";
                } else {
                    book.isIssued = true;
                    cout << "Book issued successfully!\n";
                }

                return;
            }
        }

        cout << "Book not found.\n";
    }

    // Return Book
    void returnBook() {
        int id;

        cout << "Enter Book ID to return: ";
        cin >> id;

        for (auto &book : books) {
            if (book.id == id) {

                if (!book.isIssued) {
                    cout << "Book was not issued.\n";
                } else {
                    book.isIssued = false;
                    cout << "Book returned successfully!\n";
                }

                return;
            }
        }

        cout << "Book not found.\n";
    }

    // Search by Title
    void searchByTitle() {
        string title;

        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        bool found = false;

        for (auto &book : books) {
            if (book.title == title) {

                cout << "\nBook Found!\n";
                cout << "ID: " << book.id << endl;
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;

                found = true;
            }
        }

        if (!found) {
            cout << "Book not found.\n";
        }
    }

    // Search by Author
    void searchByAuthor() {
        string author;

        cin.ignore();

        cout << "Enter Author Name: ";
        getline(cin, author);

        bool found = false;

        for (auto &book : books) {
            if (book.author == author) {

                cout << "\nBook Found!\n";
                cout << "ID: " << book.id << endl;
                cout << "Title: " << book.title << endl;

                found = true;
            }
        }

        if (!found) {
            cout << "No books found by this author.\n";
        }
    }
};

// Main Function
int main() {

    Library lib;
    int choice;

    do {

        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Display Books\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Search Book by Title\n";
        cout << "7. Search Book by Author\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            lib.addBook();
            break;

        case 2:
            lib.addMember();
            break;

        case 3:
            lib.displayBooks();
            break;

        case 4:
            lib.issueBook();
            break;

        case 5:
            lib.returnBook();
            break;

        case 6:
            lib.searchByTitle();
            break;

        case 7:
            lib.searchByAuthor();
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
