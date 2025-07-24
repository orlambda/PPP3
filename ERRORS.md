A list of errors found in PPP3
I often use the terse notation: s/old text/new text/

check commits for other bugs found

p515: s/Vector(vector&&)/Vector(Vector&&)
p515: s/Vector<vector<int>>/Vector<Vector<int>>
p520: I can't find std::binary_operation - is this std::relation?
p520: first mention of binary_operation: possibly s/binary_operation<B,T,U>()/binary_operation<B,T,T>()