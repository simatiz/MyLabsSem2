#include "date.h"
using namespace std;

Date::Date(const string& s)
{
    this->month = stoi(s.substr(0, 2));
    this->day = stoi(s.substr(3, 2));
    this->year = stoi(s.substr(6, 4));
    date_str = s;
}