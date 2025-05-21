//
// Created by Orlando Shamlou on 21/05/2025.
//

#include "Book.h"

// Member variables:
// string isbn
// string title
// string author
// year_month_day publication_date
// Genre genre;
// int available_copies
// int checked_out_copies

Book::Book(string p_isbn, string p_title, string p_author, year_month_day p_publication_date, Genre p_genre, int p_copies)
    : isbn {p_isbn}, title{p_title}, author {p_author}, publication_date{p_publication_date}, genre {p_genre},
    available_copies{p_copies}, checked_out_copies{0}
    {
    // check isbn is valid
    if (!valid_isbn(isbn)) {
        throw runtime_error("Invalid ISBN");
    }
    if (title.empty()) {
        throw runtime_error("Missing title");
    }
    if (author.empty()) {
        throw runtime_error("Missing author");
    }
    if (genre < fiction || p_genre > children) {
        throw runtime_error("Invalid genre");
    }
    if (available_copies < 0) {
        throw runtime_error("Number of copies must be 0 or greater");
    }
}

void Book::amend_info(string p_isbn, string p_title, string p_author, Genre p_genre, year_month_day p_publication_date) {
    isbn = p_isbn;
    title = p_title;
    author = p_author;
    genre = p_genre;
    publication_date = p_publication_date;
    if (!valid_isbn(isbn)) {
        throw runtime_error("Invalid ISBN");
    }
    if (title.empty()) {
        throw runtime_error("Missing title");
    }
    if (author.empty()) {
        throw runtime_error("Missing author");
    }
    if (genre < fiction || p_genre > children) {
        throw runtime_error("Invalid genre");
    }
}

string Book::get_isbn() const {
    return isbn;
}

string Book::get_title() const {
    return title;
}

string Book::get_author() const {
    return author;
}

Book::Genre Book::get_genre() const {
    return genre;
}

year_month_day Book::get_publication_date() const {
    return publication_date;
}

bool Book::is_available() const {
    if (available_copies > 0) {
        return true;
    }
    return false;
}

void Book::check_in() {
    if (checked_out_copies < 1) {
        throw runtime_error("No copies checked out");
    }
    ++available_copies;
    --checked_out_copies;
}

void Book::check_out() {
    if (available_copies < 1) {
        throw runtime_error("No available copies");
    }
    --available_copies;
    ++checked_out_copies;
}

void Book::add_copy() {
    ++available_copies;
}

void Book::remove_copy(bool was_checked_out) {
    // If the copy was checked out,
    // Make sure there were checked_out_copies. if so, --
    if (was_checked_out) {
        if (checked_out_copies < 1) {
            throw runtime_error("No copies checked out");
        }
        --checked_out_copies;
    // else copy was an available copy
    // Make sure there are available copies. If so, --
    } else {
        if (available_copies < 1) {
            throw runtime_error("No available copies");
        }
        --available_copies;
    }
}

bool valid_isbn(string isbn) {
    // Fictional check
    // 13 characters long
    if (isbn.length() != 13) {
        return false;
    }
    // first 12 characters are digits
    for (int i = 0; i < 12; ++i) {
        if (isbn[i] < '0' || isbn[i] > '9') {
            return false;
        }
    }
    // last character is a digit or 'X'
    if (isbn[12] < '0' || isbn[12] > '9') {
        if (isbn[12] != 'X') {
            return false;
        }
    }
    return true;
}

bool operator==(const Book& a, const Book& b) {
    return (a.get_isbn() == b.get_isbn());
}

bool operator!=(const Book& a, const Book& b) {
    return !(a==b);
}

ostream& operator<<(ostream& os, const Book&a) {
    os << a.get_title() << endl;
    os << a.get_author() << endl;
    os << a.get_genre() << endl;
    os << a.get_isbn() << endl;
    return os;
}