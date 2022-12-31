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
        for (int i = 0; i < stream.size() - 14; i++) {
            set<char> seq;

            for (int j = 0; j < 14; j++) {
                seq.insert(stream[i + j]);
            }

            if (seq.size() == 14) {
                cout << i + 14 << "\n";
                return 0;
            }
        }
    }
}