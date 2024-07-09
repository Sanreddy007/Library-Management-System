#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <algorithm>

struct Book {
    int id;
    std::string title;
    std::string author;
    bool isIssued;
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(int id, const std::string &title, const std::string &author);
    void searchBookByID(int id);
    void searchBookByTitle(const std::string &title);
    void issueBook(int id, const std::string &student);
    void returnBook(int id);
    void listAllBooks();
    void deleteBook(int id);
};

#endif // LIBRARY_H
