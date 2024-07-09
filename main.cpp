#include "Library.h"

int main() {
    Library library;
    int choice, id;
    std::string title, author, student;

    while (true) {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add Book\n2. Search Book by ID\n3. Search Book by Title\n4. Issue Book\n5. Return Book\n6. List All Books\n7. Delete Book\n8. Exit\n";
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
                library.searchBookByID(id);
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
                std::cin.ignore();
                std::cout << "Enter student name: ";
                std::getline(std::cin, student);
                library.issueBook(id, student);
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
                std::cout << "Invalid choice. Try again.\n";
        }
    }
}
