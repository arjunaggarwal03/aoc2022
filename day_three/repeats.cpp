#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    ifstream file ("rucksacks.txt");
    string line;
    vector<char> repeats;

    if (file.is_open()) {
        while(getline(file, line)) {
            cout << line << "\n";
            for (int i = 0; i < line.size() / 2; i++) {
                if (line[i] == line[line.size() / 2 + i]) {
                    cout << line[i] << line[line.size() / 2 + i] << "\n";
                    repeats.push_back(line[i]);
                }
            }
        }
    }

    cout << repeats[0] << repeats[1] << repeats[2] << "\n";
}