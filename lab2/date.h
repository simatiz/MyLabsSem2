#pragma once
#include <string>
#include <iostream>
using namespace std;

class Date {
    int day, month, year;
    string date_str;
public:
    Date() = default;
    Date(const string&);
    string get_date_str() const { return date_str; }
    int get_day() const { return day; }
    int get_month() const { return month; }
    int get_year() const { return year; }
    int date_in_months() const { return 12 * year + month; }
};