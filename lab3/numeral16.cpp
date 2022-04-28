#include "numeral16.h"

numeral16::numeral16(int num_10) {
    if (!num_10) num_16_str = "0";
    else {
        int base = 16;
        string temp;
        int remainder;
        while (num_10) {
            remainder = num_10 % base;
            if (remainder >= 10) {
                temp += (char)(remainder + 55);
            }
            else {
                temp += (char)(remainder + 48);
            }
            num_10 /= base;
        }
        int length = temp.length();
        for (int j = length - 1; j >= 0; --j) {
            num_16_str += temp[j];
        }
    }
}

numeral16 numeral16::operator ++() {
    int num_10 = stoi(num_16_str, nullptr, 16);
    this->num_16_str = numeral16(++num_10).num_16_str;
    return *this;
}

const numeral16 numeral16::operator +(const numeral16& obj) {
    numeral16 temp;
    temp.num_16_str = numeral16(stoi(num_16_str, nullptr, 16) + stoi(obj.num_16_str, nullptr, 16)).num_16_str;
    return temp;
}

const numeral16 numeral16::operator +=(const numeral16& obj) {
    num_16_str = numeral16(stoi(num_16_str, nullptr, 16) + stoi(obj.num_16_str, nullptr, 16)).num_16_str;
    return *this;
}

string numeral16::convert_to_binary_short() {
    string num_2;
    for (char c : num_16_str) {
        switch (c) {
        case '0':
            num_2 += "0000";
            break;
        case '1':
            num_2 += "0001";
            break;
        case '2':
            num_2 += "0010";
            break;
        case '3':
            num_2 += "0011";
            break;
        case '4':
            num_2 += "0100";
            break;
        case '5':
            num_2 += "0101";
            break;
        case '6':
            num_2 += "0110";
            break;
        case '7':
            num_2 += "0111";
            break;
        case '8':
            num_2 += "1000";
            break;
        case '9':
            num_2 += "1001";
            break;
        case 'A':
            num_2 += "1010";
            break;
        case 'B':
            num_2 += "1011";
            break;
        case 'C':
            num_2 += "1100";
            break;
        case 'D':
            num_2 += "1101";
            break;
        case 'E':
            num_2 += "1110";
            break;
        case 'F':
            num_2 += "1111";
            break;
        }
    }
    int i = 0;
    bool found = true;
    string extra_zeros;
    while (i <= 3 && found) {
        found = false;
        if (num_2[i] == '0') {
            extra_zeros += num_2[i];
            found = true;
        }
        i++;
    }
    num_2.replace(0, extra_zeros.length(), "");
    return num_2;
}

string numeral16::convert_to_binary_long() {
    string num_2;
    int num_10 = stoi(num_16_str, nullptr, 16);
    if (!num_10) num_2 = "0";
    else {
        int base = 2;
        string temp;
        int remainder;
        while (num_10) {
            remainder = num_10 % base;
            temp += (char)(remainder + 48);
            num_10 /= base;
        }
        int length = temp.length();
        for (int j = length - 1; j >= 0; --j) {
            num_2 += temp[j];
        }
    }
    return num_2;
}