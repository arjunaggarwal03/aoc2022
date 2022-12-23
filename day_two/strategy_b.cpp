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
    map<char, char> losses;
    map<char, int> values;

    wins['A'] = 'P'; // paper beats their rock
    wins['B'] = 'S'; // scissors beats their paper
    wins['C'] = 'R'; // rock beats their scissors

    draws['A'] = 'R'; // rock draws with rock
    draws['B'] = 'P'; // paper draws with paper
    draws['C'] = 'S'; // scissors draws with scissors

    losses['A'] = 'S'; // scissors loses to their rock
    losses['B'] = 'R'; // rock loses to their paper
    losses['C'] = 'P'; // paper loses to their scissors

    values['R'] = 1;
    values['P'] = 2;
    values['S'] = 3;

    points = 0;
    if (file.is_open()) {
        while(getline(file, line)) {
            char their_move = line[0];
            char outcome = line[2];

            if (outcome == 'X') {
                points += values[losses[their_move]];
            }
            else if (outcome == 'Y') {
                points += 3;
                points += values[draws[their_move]];
            }
            else {
                points += 6;
                points += values[wins[their_move]];
            }
        }
    }

    cout << points << "\n";
}