#ifndef TASK5_MEMBER_H
#define TASK5_MEMBER_H

#include <iostream>
#include "Book.h"
#include <vector>

class Member {
private:
    std::string m_name;
    std::string m_ContactInfo;
    std::vector<Book *> m_BorrowedBooks;
public:
    Member(const std::string &name, const std::string &info) :
            m_name(name),
            m_ContactInfo(info) {}

public:
    std::string get_name() const {
        return m_name;
    }

    std::string get_info() const {
        return m_ContactInfo;
    }

    void BorrowBook(Book *book) {
        m_BorrowedBooks.push_back(book);
        book->set_availability(false);
    }

    void returnBook(Book *book) {
        for (auto it = m_BorrowedBooks.begin(); it != m_BorrowedBooks.end(); ++it) {
            if (*it == book) {
                m_BorrowedBooks.erase(it);
                book->set_availability(true);
                break;
            }
        }
    }

    std::vector<Book *> get_BorroedBooks() const {
        return m_BorrowedBooks;
    }
};

#endif //TASK5_MEMBER_H
