#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <stack>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file ("cargo.txt");
    string line;
    vector< stack<char> > crates;


    if (file.is_open()) {
        while(getline(file, line)) {
            if (line.substr(0, 4) == "move") {
            }
        }
    }

}