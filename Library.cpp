#include "Library.h"

void Library::addBook(int id, const std::string &title, const std::string &author) {
    Book newBook = {id, title, author, false};
    books.push_back(newBook);
    std::cout << "Book added successfully!\n";
}

void Library::searchBookByID(int id) {
    for (const auto &book : books) {
        if (book.id == id) {
            std::cout << "Book found: " << book.title << " by " << book.author << (book.isIssued ? " (Issued)\n" : " (Available)\n");
            return;
        }
    }
    std::cout << "Book not found!\n";
}

void Library::searchBookByTitle(const std::string &title) {
    for (const auto &book : books) {
        if (book.title == title) {
            std::cout << "Book found: ID " << book.id << " by " << book.author << (book.isIssued ? " (Issued)\n" : " (Available)\n");
            return;
        }
    }
    std::cout << "Book not found!\n";
}

void Library::issueBook(int id, const std::string &student) {
    for (auto &book : books) {
        if (book.id == id) {
            if (!book.isIssued) {
                book.isIssued = true;
                std::cout << "Book issued to " << student << "\n";
                return;
            } else {
                std::cout << "Book is already issued.\n";
                return;
            }
        }
    }
    std::cout << "Book not found!\n";
}

void Library::returnBook(int id) {
    for (auto &book : books) {
        if (book.id == id) {
            if (book.isIssued) {
                book.isIssued = false;
                std::cout << "Book returned successfully!\n";
                return;
            } else {
                std::cout << "Book was not issued.\n";
                return;
            }
        }
    }
    std::cout << "Book not found!\n";
}

void Library::listAllBooks() {
    std::sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
        return a.id < b.id;
    });

    for (const auto &book : books) {
        std::cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << (book.isIssued ? " (Issued)\n" : " (Available)\n");
    }
}

void Library::deleteBook(int id) {
    books.erase(std::remove_if(books.begin(), books.end(), [id](const Book &book) {
        return book.id == id;
    }), books.end());
    std::cout << "Book deleted successfully!\n";
}
