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
    ifstream file ("stream.txt");
    int overlaps = 0;

    if (file.is_open()) {
        string stream = getline(file, line);

        for (int i = 0; i < stream.size() - 4; i++) {
            
        }
    }

    cout << overlaps << "\n";
}