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
            string line_b, line_c;
            getline(file, line_b);
            getline(file, line_c);
            cout << line << line_b << line_c << "\n";
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