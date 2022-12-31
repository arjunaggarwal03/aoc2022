#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <set>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file ("stream.txt");
    int overlaps = 0;

    if (file.is_open()) {
        string stream;

        getline(file, stream);
        for (int i = 0; i < stream.size() - 4; i++) {
            set<char> seq;

            seq.insert(stream[i]);
            seq.insert(stream[i + 1]);
            seq.insert(stream[i + 2]);
            seq.insert(stream[i + 3]);

            if (seq.size() == 4) {
                cout << i + 4 << "\n";
                return 0;
            }
        }
    }
}