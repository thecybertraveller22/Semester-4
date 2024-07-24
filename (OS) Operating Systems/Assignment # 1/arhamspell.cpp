#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool checkSpelling(const string& text_to_check) 
{
    ifstream infile("words.txt");
    if (!infile) 
    {
        cerr << "Error opening file: words.txt" << endl;
        return false;
    }

    string word;
    bool found = false;
    while (infile >> word) 
    {
        if (word == text_to_check) 
        {
            found = true;
            break;
        }
    }

    infile.close();

    return found;
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        cerr << "Usage: " << argv[0] << " <text_to_check>" << endl;
        return 1;
    }

    string text_to_check = argv[1];
    bool isCorrect = checkSpelling(text_to_check);

    if (isCorrect) 
    {
        cout << "**************************************Correct Spelling**************************************" << endl;
        return true;
    } 
    else 
    {
        cout << "**************************************In-Correct Spelling**************************************" << endl;
        return false;
    }
}
