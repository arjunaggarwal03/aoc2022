#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <stack>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// map {file : [file, file, file]}

int main() {
    ifstream file ("commands.txt");
    string line;

    map<string, vector<string> > children;
    map<string, string> parent;
    map<string, int> size;

    if (file.is_open()) {
        string curr_dir;
        string prev_dir;

        while(getline(file, line)) {
            if (line.substr(0, 4) == "$ cd") { // change directories
                if (line == "$ cd ..") {
                    curr_dir = prev_dir;
                    prev_dir = parent[curr_dir];
                }
                else {
                    prev_dir = curr_dir;
                    
                }
            }
        }
    }

}