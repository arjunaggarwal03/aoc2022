#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file ("calories.txt");
    string line;
    vector<int> counts;
    int running_count;

    if (file.is_open()) {
        while(getline(file, line)) {
            if (line == "\n") {
                counts.push_back(running_count);
                running_count = 0;
            }
            else {
                running_count += stoi(line);
            }
        }
    }

    sort(counts.begin(), counts.end(), greater<int>());
    cout << counts[0] + counts[1] + counts[2];
}