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
            for (int i = 0; i < strlen(line.c_str()) / 2; i++) {
                if (line[i] == line[strlen(line.c_str()) + i - 1]) {
                    repeats.push_back(line[i]);
                }
            }
        }
    }

    cout << repeats[0] << "\n";
}