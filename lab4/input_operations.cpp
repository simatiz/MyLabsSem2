#include "input_operations.h"
#include <string>

vector<int> input_points() {
    vector<int> coordinates;
    string coordinates_str;
    int x, y;
    cin.ignore();
    for (int i = 1; i < 5; ++i) {
        cout << "Point " << i << ":" << endl;
        getline(cin, coordinates_str);
        auto input_str = split(coordinates_str, ',');
        x = stoi(input_str[0]);
        y = stoi(input_str[1]);
        coordinates.push_back(x);
        coordinates.push_back(y);
    }
    return coordinates;
}

vector<string> split(string str, char sep) {
    vector<string> words;
    string temp_str;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == sep || i == str.length() - 1) {
            if (str[i] == sep) {
                words.push_back(temp_str);
                temp_str = "";
            }
            else {
                temp_str += str[i];
                if (!temp_str.empty()) words.push_back(temp_str);
            }
        }
        else {
            temp_str += str[i];
        }
    }
    return words;
}