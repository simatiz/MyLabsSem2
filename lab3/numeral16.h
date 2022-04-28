#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class numeral16 {
    string num_16_str;
public:
    numeral16() = default;
    explicit numeral16(const string& num_16_str) { this->num_16_str = num_16_str; }
    explicit numeral16(int);
    string get_num_16_str() const { return  num_16_str; }
    numeral16 operator ++();
    const numeral16 operator +(const numeral16& obj);
    const numeral16 operator += (const numeral16& obj);
    string convert_to_binary_short();
    string convert_to_binary_long();
};