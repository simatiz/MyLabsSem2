#pragma once
#include "product.h"
#include <iostream>
#include <vector>
using namespace std;

vector<Product> get_product_list(int);

bool is_number(string);
bool is_valid_date(const string&);

vector<string> split(string, char);
vector<Product> get_expired_products(const string&, const vector<Product>&);

void output_products(const vector<Product>&);
bool is_earlier(const Date&, const Date&);