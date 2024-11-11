#include <iostream>
using std::cin, std::cout, std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string, std::stoi;
#include <algorithm>
using std::find;
#include <iterator>
using std::distance;

int find_name(vector<string> names, string name);

int main() {
    vector<string> names;
    vector<int> scores;
    cout << "Enter names and scores: " << endl;
    while(true)
    {
        string name;
        int score;
        cin >> name >> score;
        if (name == "NoName" && score == 0)
        {
            break;
        }
        if (find_name(names, name) != -1)
        {
            cout << "Name already entered." << endl;
            return 1;
        }
        names.push_back(name);
        scores.push_back(score);
    }
    for (int i = 0; i < names.size() && i < scores.size(); ++i)
    {
        cout << names[i] << " " << scores[i] << endl;
    }
    while (true)
    {
        cout << "Enter a name or a score: ";
        string input;
        int score{0};
        cin >> input;
        if (input == "ExitProgram")
        {
            return 0;
        }
        bool is_number = true;
        for (char c : input)
        {
            if (c < '0' || c > '9')
            {
                is_number = false;
                break;
            }
        }
        if (is_number)
        {
            bool found_score = false;
            score = stoi(input);
            for (int i = 0; i < scores.size(); ++i)
            {
                if (scores[i] == score)
                {
                    found_score = true;
                    cout << names[i] << " " << scores[i] << endl;
                }
            }
            if (!found_score)
            {
                cout << "Score not found." << endl;
            }
        }
        else
        {
            int i = find_name(names, input);
            if (i == -1)
            {
                cout << "Name not found." << endl;
            }
            else
            {
                cout << names[i] << " " << scores[i] << endl;
            }
        }
    }
    return 0;
}

// Returns index of name in names
// -1 means not found
int find_name(vector<string> names, string name)
{
    // Based on Stroustrup PPP 21.2.1
    auto p = find(names.begin(), names.end(), name);
    if (p != names.end())
    {
        return distance(names.begin(), p);
    }
    return -1;
}