#include "product.h"
using namespace std;

Product::Product(string name, Date release_date, Date expire_date) {
    this->name = name;
    this->release_date = release_date;
    this->expire_date = expire_date;
}

void Product::print() const {
    string r_date = release_date.get_date_str();
    string e_date = expire_date.get_date_str();
    cout << "Product name: " << name << "; release date: " << r_date << "; expire date: " << e_date << endl;
}