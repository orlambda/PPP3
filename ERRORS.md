A list of errors found in PPP3
I often use the terse notation: s/old text/new text/

check commits for other bugs found

p515: s/Vector(vector&&)/Vector(Vector&&)
p515: s/Vector<vector<int>>/Vector<Vector<int>>
p520: I can't find std::binary_operation - is this std::relation?
p520: first mention of binary_operation: possibly s/binary_operation<B,T,U>()/binary_operation<B,T,T>()
p554/558: are template<forward_iterator Iter> and template<input_iterator Iter> meant to be the same?
p558: s/return curr==b.curr;/return *this==*b; (CHECK THIS)
p592: s/auto p = lst.end()/auto p = lst.end()-1