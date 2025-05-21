//
// Created by Orlando Shamlou on 21/05/2025.
//

#include "Patron.h"

Patron::Patron(string p_name, int p_library_card_id, int p_fees_owed)
: name{p_name}, library_card_id{p_library_card_id}, fees_owed{p_fees_owed}
{
    if (name.empty()) {
        throw runtime_error("Must enter name");
    }
    if (library_card_id < 0) {
        throw runtime_error("Enter valid library card id");
    }
}

void Patron::set_fee(int p_fee) {
    fees_owed = p_fee;
}

int Patron::get_fee() const {
    return fees_owed;
}

string Patron::get_name() const {
    return name;
}

int Patron::get_id() const {
    return library_card_id;
}

bool owes_fee(const Patron& p) {
    return (p.get_fee() > 0);
}