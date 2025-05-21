//
// Created by Orlando Shamlou on 21/05/2025.
//

#ifndef PATRON_H
#define PATRON_H

#include <string>

using namespace std;

class Patron {
public:
    Patron(string p_name, int p_library_card_id, int p_fees_owed);
    void set_fee(int p_fee);
    int get_fee() const;
    string get_name() const;
    int get_id() const;
private:
    string name;
    int library_card_id;
    int fees_owed;
};

bool owes_fee(const Patron& p);


#endif //PATRON_H
