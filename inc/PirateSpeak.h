#ifndef PIRATESPEAK_H
#define PIRATESPEAK_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class Pirate {
public:
    string translateWord(string word) {
        ifstream fin("C:/Users/subaw/OneDrive/Desktop/HW12/files/pirate.csv", ios::in);
        string english, pirate;

        while (getline(fin, english, ',') && getline(fin, pirate)) {
            if (english == word) {
                fin.close();
                return pirate;
            }
        }

        fin.close();
        return word;
    }

    void addToFile(string english, string pirate) {
        ofstream fout("C:/Users/subaw/OneDrive/Desktop/HW12/files/pirate.csv", ios::app);

        if (!fout) {
            cout << "File did not open for writing." << endl;
            return;
        }

        fout << english << "," << pirate << endl;
        fout.close();

        cout << "Word added successfully!" << endl;
    }
};
#endif