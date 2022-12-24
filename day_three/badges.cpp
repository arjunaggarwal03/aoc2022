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
    string sack_a, sack_b, sack_c;
    vector<char> badges;

    if (file.is_open()) {
        while(getline(file, sack_a)) {
            getline(file, sack_b);
            getline(file, sack_c);
            
            for (char item : sack_a) {
                if (find(sack_b.begin(), sack_b.end(), item) != sack_b.end() &&
                    find(sack_c.begin(), sack_c.end(), item) != sack_c.end()) {
                    badges.push_back(item);
                    break;
                }
            }
        }
    }

    int total_priority = 0;
    for (char item : badges) {
        if (isupper(item)) {
            total_priority += int(item) - 38;
        }
        else {
            total_priority += int(item) - 96;
        }
    }

    cout << total_priority << "\n";
}