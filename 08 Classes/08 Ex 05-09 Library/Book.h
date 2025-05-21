//
// Created by Orlando Shamlou on 21/05/2025.
//

#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <chrono>

using namespace std;
using namespace chrono;


class Book {
public:
    enum Genre {
        fiction, nonfiction, periodical, biography, children
    };
    Book(string p_isbn, string p_title, string p_author, year_month_day p_publication_date, Genre p_genre, int p_copies);
    void amend_info(string p_isbn, string p_title, string p_author, Genre p_genre,year_month_day p_publication_date);
    string get_isbn() const;
    string get_title() const;
    string get_author() const;
    Genre get_genre() const;
    year_month_day get_publication_date() const;
    bool is_available() const;
    void check_in();
    void check_out();
    void add_copy();
    void remove_copy(bool was_checked_out);
private:
    string isbn;
    string title;
    string author;
    Genre genre;
    year_month_day publication_date;
    int available_copies;
    int checked_out_copies;
};

bool valid_isbn(string p_isbn);
bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
ostream& operator<<(ostream& os, const Book&a);

#endif //BOOK_H
