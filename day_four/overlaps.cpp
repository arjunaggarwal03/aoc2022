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
    ifstream file ("assignments.txt");
    string line;

    if (file.is_open()) {
        while(getline(file, line)) {
            string assignment_a = line.substr(0, line.find(","));
            string assignment_b = line.substr(line.find(",") + 1, line.size() - line.find(","));
            cout << assignment_a << assignment_b << "\n";
        }
    }
}