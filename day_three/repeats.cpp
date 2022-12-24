#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <map>

using namespace std;

int main() {
    ifstream file ("rucksacks.txt");
    string line;
    vector<char> repeats;

    if (file.is_open()) {
        while(getline(file, line)) {
            bool found = false;
            int i = 0;
            while (!found && i < line.size() / 2) {
                for (int j = line.size() / 2; j < line.size(); j++) {
                    if (line[i] == line[j]) {
                        repeats.push_back(line[i]);
                        found = true;
                        break;
                    }
                }
                i++;
            }
            found = false;
        }
    }

    int total_priority = 0;
    for (char item : repeats) {
        if (isupper(item)) {
            total_priority += int(item) - 38;
        }
        else {
            total_priority += int(item) - 96;
        }
    }

    cout << total_priority << "\n";
}