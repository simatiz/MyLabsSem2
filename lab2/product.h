#pragma once
#include "date.h"
#include <string>
#include <iostream>
using namespace std;

class Product {
    string name;
    Date release_date;
    Date expire_date;
public:
    Product(string, Date, Date);
    Date get_release_date() const { return release_date; }
    Date get_expire_date() const { return expire_date; }
    void print() const;
};