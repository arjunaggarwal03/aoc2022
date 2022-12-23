#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int main() {
    ifstream file ("rucksacks.txt");
    string line;
    set<char> repeats;

    if (file.is_open()) {
        while(getline(file, line)) {
            for (int i = 0; i < line.size() / 2; i++) {
                for (int j = line.size() / 2; j < line.size(); j++) {
                    if (line[i] == line[j]) {
                        repeats.insert(line[i]);
                    }
                }
            }
        }
    }

    for (char item : repeats) {
        cout << item << "\n";
    }
}