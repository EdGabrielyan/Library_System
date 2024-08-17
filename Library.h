#ifndef TASK5_LIBRARY_H
#define TASK5_LIBRARY_H

#include <iostream>
#include "Book.h"
#include "Member.h"
#include <vector>

class Library {
private:
    std::vector<Book *> books;
    std::vector<Member *> members;
public:
    void add_book(const std::string &title, const std::string &author, const std::string &genre) {
        Book *book = new Book(title, author, genre);
        books.push_back(book);
    }
    void add_member(const std::string &name, const std::string &info) {
        Member *member = new Member(name, info);
        members.push_back(member);
    }

    void displayBooks() const {
        std::cout << "---- Available Books ----" << std::endl;
        for (const auto& book : books) {
            if (book->ISavailable()) {
                std::cout << "Title: " << book->get_title() << std::endl;
                std::cout << "Author: " << book->get_author() << std::endl;
                std::cout << "Genre: " << book->get_genre() << std::endl;
                std::cout << "Availability: " << (book->ISavailable() ? "Available" : "Not Available") << std::endl;
                std::cout << "------------------------" << std::endl;
            }
        }
    }

    void displayMembers() const {
        std::cout << "---- Registered Members ----" << std::endl;
        for (const auto& member : members) {
            std::cout << "Name: " << member->get_name() << std::endl;
            std::cout << "Contact Info: " << member->get_info() << std::endl;
            std::cout << "---------------------------" << std::endl;
        }
    }

    Book* findBookByTitle(const std::string& title) const {
        for (const auto& book : books) {
            if (book->get_title() == title) {
                return book;
            }
        }
        return nullptr;
    }

    Book* findBookByAuthor(const std::string& author) const {
        for (const auto& book : books) {
            if (book->get_author() == author) {
                return book;
            }
        }
        return nullptr;
    }

    Book* findBookByGenre(const std::string& genre) const {
        for (const auto& book : books) {
            if (book->get_genre() == genre) {
                return book;
            }
        }
        return nullptr;
    }

    Member* findMemberByName(const std::string& name) const {
        for (const auto& member : members) {
            if (member->get_name() == name) {
                return member;
            }
        }
        return nullptr;
    }
};

#endif //TASK5_LIBRARY_H
