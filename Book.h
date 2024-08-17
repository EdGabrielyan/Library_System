#ifndef TASK5_BOOK_H
#define TASK5_BOOK_H

#include <iostream>

class Book {
private:
    std::string m_title;
    std::string m_author;
    std::string m_genre;
    bool m_availability;
public:
    Book(const std::string &title, const std::string &author, const std::string &genre)
            : m_title(title),
              m_author(author),
              m_genre(genre),
              m_availability(true) {}

public:
    std::string get_title() const {
        return m_title;
    }

    std::string get_author() const {
        return m_author;
    }

    std::string get_genre() const {
        return m_genre;
    }

    bool ISavailable() const {
        return m_availability;
    }

    void set_availability(bool availability) {
        m_availability = availability;
    }
};

#endif //TASK5_BOOK_H
