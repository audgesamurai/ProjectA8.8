#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;

int main() {
    string fileName;
    cout << "File name? ";
    cin >> fileName;

    ifstream file(fileName);
    if (!file) {
        cout << "Couldn’t open that one. Try again." << endl;
        return 1;
    }

    int letters[26] = {0};
    int total = 0;
    char c;

    while (file.get(c)) {
        if (isalpha(c)) {
            c = toupper(c);
            letters[c - 'A']++;
            total++;
        }
    }

    file.close();

    if (total == 0) {
        cout << "No letters found. That file's empty or just weird." << endl;
        return 0;
    }

    cout << fixed << setprecision(1);
    for (int i = 0; i < 26; ++i) {
        char letter = 'A' + i;
        double percent = (letters[i] * 100.0) / total;

        cout << letter << ": ";
        cout << setw(4) << percent << "%";

        if ((i + 1) % 4 == 0 || i == 25)
            cout << endl;
        else
            cout << "   ";
    }

    return 0;
}

