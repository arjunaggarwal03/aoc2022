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
    int overlaps = 0;

    if (file.is_open()) {
        while(getline(file, line)) {
            string assignment_a = line.substr(0, line.find(","));
            string assignment_b = line.substr(line.find(",") + 1, line.size() - line.find(","));
            int start_a = stoi(assignment_a.substr(0, assignment_a.find("-")));
            int end_a = stoi(assignment_a.substr(assignment_a.find("-") + 1, assignment_a.size() - assignment_a.find("-")));
            int start_b = stoi(assignment_b.substr(0, assignment_b.find("-")));
            int end_b = stoi(assignment_b.substr(assignment_b.find("-") + 1, assignment_b.size() - assignment_b.find("-")));
            
            if (start_a <= start_b) {
                if (end_a >= end_b) {
                    overlaps++;
                }
            }
            else if (start_b <= start_a) {
                if (end_b >= end_a) {
                    overlaps++;
                }
            }
        }
    }

    cout << overlaps << "\n";
}