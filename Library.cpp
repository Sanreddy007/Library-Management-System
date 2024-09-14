#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    std::string title;
    std::string author;
    bool isIssued;

    Book() : id(0), title(""), author(""), isIssued(false) {}
    Book(int id, const std::string& title, const std::string& author)
        : id(id), title(title), author(author), isIssued(false) {}
};

class Library {
private:
    static const int MAX_BOOKS = 100;
    Book books[MAX_BOOKS];  
    int bookCount;

public:
    Library() : bookCount(0) {}

    void addBook(int id, const std::string& title, const std::string& author);
    void searchBookById(int id) const;
    void searchBookByTitle(const std::string& title) const;
    void issueBook(int id);
    void returnBook(int id);
    void listAllBooks() const;
    void deleteBook(int id);
};

void Library::addBook(int id, const std::string& title, const std::string& author) {
    if (bookCount < MAX_BOOKS) {
        books[bookCount++] = Book(id, title, author);
        std::cout << "Book added successfully.\n";
    } else {
        std::cout << "Library is full. Cannot add more books.\n";
    }
}

void Library::searchBookById(int id) const {
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].id == id) {  
            std::cout << "Book found: " << books[i].title << " by " << books[i].author << "\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Library::searchBookByTitle(const std::string& title) const {
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].title == title) {  
            std::cout << "Book found: " << books[i].title << " by " << books[i].author << "\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Library::issueBook(int id) {
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].id == id) {
            if (!books[i].isIssued) {
                books[i].isIssued = true;
                std::cout << "Book issued successfully.\n";
                return;
            } else {
                std::cout << "Book is already issued.\n";
                return;
            }
        }
    }
    std::cout << "Book not found.\n";
}

void Library::returnBook(int id) {
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].id == id) {  
            if (books[i].isIssued) {
                books[i].isIssued = false;
                std::cout << "Book returned successfully.\n";
                return;
            } else {
                std::cout << "Book was not issued.\n";
                return;
            }
        }
    }
    std::cout << "Book not found.\n";
}

void Library::listAllBooks() const {
    if (bookCount == 0) {
        std::cout << "No books in the library.\n";
        return;
    }
    for (int i = 0; i < bookCount; ++i) {
        std::cout << "ID: " << books[i].id << ", Title: " << books[i].title << ", Author: " << books[i].author;
        if (books[i].isIssued) {
            std::cout << " [Issued]";
        }
        std::cout << "\n";
    }
}

void Library::deleteBook(int id) {
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].id == id) {  
            for (int j = i; j < bookCount - 1; ++j) {
                books[j] = books[j + 1];  
            }
            bookCount--;
            std::cout << "Book deleted successfully.\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}

int main() {
    Library library;
    int choice, id;
    std::string title, author;

    while (true) {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add New Book\n";
        std::cout << "2. Search Book by ID\n";
        std::cout << "3. Search Book by Title\n";
        std::cout << "4. Issue Book\n";
        std::cout << "5. Return Book\n";
        std::cout << "6. List All Books\n";
        std::cout << "7. Delete Book\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter book ID: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Enter book title: ";
            std::getline(std::cin, title);
            std::cout << "Enter book author: ";
            std::getline(std::cin, author);
            library.addBook(id, title, author);
            break;
        case 2:
            std::cout << "Enter book ID: ";
            std::cin >> id;
            library.searchBookById(id);
            break;
        case 3:
            std::cin.ignore();
            std::cout << "Enter book title: ";
            std::getline(std::cin, title);
            library.searchBookByTitle(title);
            break;
        case 4:
            std::cout << "Enter book ID: ";
            std::cin >> id;
            library.issueBook(id);
            break;
        case 5:
            std::cout << "Enter book ID: ";
            std::cin >> id;
            library.returnBook(id);
            break;
        case 6:
            library.listAllBooks();
            break;
        case 7:
            std::cout << "Enter book ID: ";
            std::cin >> id;
            library.deleteBook(id);
            break;
        case 8:
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
