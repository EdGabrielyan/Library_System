#include <iostream>
#include "Book.h"
#include "Member.h"
#include "Library.h"

int main() {
    Library library;

    // Adding books to the library
    library.add_book("Book 1", "Author 1", "Genre 1");
    library.add_book("Book 2", "Author 2", "Genre 2");
    library.add_book("Book 3", "Author 1", "Genre 1");

    // Adding members to the library
    library.add_member("Member 1", "Contact Info 1");
    library.add_member("Member 2", "Contact Info 2");

    // Displaying available books
    library.displayBooks();

    // Displaying registered members
    library.displayMembers();

    // Borrowing and returning books
    Book* book1 = library.findBookByTitle("Book 1");
    Book* book2 = library.findBookByAuthor("Author 1");
    Member* member1 = library.findMemberByName("Member 1");

    if (book1 && member1) {
        member1->BorrowBook(book1);
        std::cout << member1->get_name() << " borrowed " << book1->get_title() << std::endl;
    }

    if (book2 && member1) {
        member1->returnBook(book2);
        std::cout << member1->get_name() << " returned " << book2->get_title() << std::endl;
    }
    return 0;
}
