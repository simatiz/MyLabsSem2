#include <iostream>
#include "numeral16.h"
#include "input_validation.h"

int main() {
    string choice;
    int n1_decimal;
    string n2_hex;

    cout << "Enter first hex number N1 in decimal format: ";
    cin >> n1_decimal;
    cin.ignore();

    cout << "Enter second hex number N2 in hex format:\n";
    getline(cin, n2_hex);

    numeral16 N1(n1_decimal), N2(n2_hex), N3;

    cout << "First hex number N1: " << N1.get_num_16_str() << "\n";
    cout << "Second hex number N2: " << N2.get_num_16_str() << "\n";
    cout << "N1 incremented: " << (++N1).get_num_16_str() << "\n";

    choice = input_choice();

    if (choice == "d") {
        int num;
        cout << "Enter a number (in decimal format) to increase N2 by: ";
        cin >> num;

        N2 += numeral16(num);
        cout << "N2 after adding " << num << " to it: " << N2.get_num_16_str() << "\n";
    }
    else {
        string num;
        cout << "Enter a number (in hex format) to increase N2 by:" << "\n";
        getline(cin, num);

        N2 += numeral16(num);
        cout << "N2 after adding " << num << " to it: " << N2.get_num_16_str() << "\n";
    }

    N3 = N1 + N2;
    cout << "Third hex number N3 (N3 = N1 + N2): " << N3.get_num_16_str() << "\n";

    string N3_binary_1 = N3.convert_to_binary_long();
    cout << "N3 converted to binary using the first method: " << N3_binary_1 << "\n";

    string N3_binary_2 = N3.convert_to_binary_short();
    cout << "N3 converted to binary using the second method: " << N3_binary_2 << "\n";

    return 0;
}