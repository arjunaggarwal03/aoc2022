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
                    curr_dir = line.substr(5, line.size());
                    if (children.find(curr_dir) == children.end()) {
                        vector<string> temp;
                        children[curr_dir] = temp;
                    }
                }
            }
            else if (line.substr(0, 4) == "$ ls") { // listing contents
                getline(file, line);
                while(line.substr(0, 1) != "$") {
                    if (line.substr(0,3) == "dir") {
                        children[curr_dir].push_back(line.substr(5, line.size()));
                        parent[line.substr(5, line.size())] = curr_dir;
                    }
                    else {
                        if (size.find(curr_dir) == size.end()) {
                            size[curr_dir] = 0;
                        }
                        size[curr_dir] += stoi(line.substr(0, line.find(" ")));
                    }
                    getline(file, line);
                }
            }
        }
    }

}