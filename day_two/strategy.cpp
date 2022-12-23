#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ifstream file ("rps.txt");
    string line;
    int points;
    map<char, char> wins;
    map<char, char> draws;

    wins['A'] = 'Y'; // paper beats their rock
    wins['B'] = 'Z'; // scissors beats their paper
    wins['C'] = 'X'; // rock beats their scissors

    draws['A'] = 'X'; // rock draws with rock
    draws['B'] = 'Y'; // paper draws with paper
    draws['C'] = 'Z'; // scissors draws with scissors

    points = 0;
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
            else if (draws[their_move] == your_move) {
                points += 3;
            }
        }
    }

    cout << points << "\n";
}