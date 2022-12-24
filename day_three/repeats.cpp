#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file ("rucksacks.txt");
    string line;
    vector<char> repeats;

    if (file.is_open()) {
        while(getline(file, line)) {
            vector<char> compartment_a, compartment_b;

            for (int i = 0; i < line.size() / 2; i++) {
                compartment_a.push_back(line[i]);
            }

            for (int j = line.size() / 2; j < line.size(); j++) {
                compartment_b.push_back(line[j]);
            }

            for (char item : compartment_a) {
                if (find(compartment_b.begin(), compartment_b.end(), item) != compartment_b.end()) {
                    repeats.push_back(item);
                    break;
                }
            }
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