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
            if (line.substr(0, 4) != "move" && !line.empty()) { // initial data
                stack<char> temp;

                for (char item : line) {
                    if (!isspace(item)) {
                        temp.push(item);
                    }
                }

                crates.push_back(temp);
            }
            else if (line.substr(0, 4) == "move") { // instructions
                int num_items = stoi(line.substr(5, line.find("from") - 6));
                int source = stoi(line.substr(line.find("from") + 5, line.find("to") - line.find("from") - 6));
                int target = stoi(line.substr(line.find("to") + 3, line.size() - line.find("to") - 3));

                // put items in list to insert in reverse order
                vector<char> items;
                for (int i = 0; i < num_items; i++) {
                    items.push_back(crates[source - 1].top());
                    crates[source - 1].pop();
                }

                for (int j = items.size(); j > 0; j--) {
                    crates[target - 1].push(items[j - 1]);
                }
            }
        }
    }

    for (auto crate : crates) {
        if (crate.size() != 0) {
            cout << crate.top() << "\n";
        }
        else {
            cout << " \n";
        }
    }

}