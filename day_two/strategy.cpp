#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file ("rps.txt");
    string line;
    vector<int> counts;
    int points = 0;

    map<char, char> wins;
    wins.insert({'A', 'Y'}); // paper beats their rock
    wins.insert({'B', 'Z'}); // scissors beats their paper
    wins.insert({'C', 'X'}); // rock beats their scissors

    if (file.is_open()) {
        while(getline(file, line)) {
            char their_move = line[0];
            char your_move = line[2];

            if (your_move == 'X') {
                points += 1;
            }
            else if (your_move == 'Y') {
                points += 2;
            }
            else if (your_move == 'Z') {
                points += 3;
            }

            if (wins[their_move] == your_move) {
                points += 6;
            }
            else if (their_move == your_move) {
                points += 3;
            }
        }
    }

    cout << points << "\n";
}