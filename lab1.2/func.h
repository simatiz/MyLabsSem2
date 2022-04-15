#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Car {
    char name[100];
    char release_date[100];
    char sell_date[100];
};

string enter_file_mode();

void create_fist_file(string, int, string);
void output_file(string);
void create_list_recent_cars(string, string, int, int);
void output_worn_cars(string);
void output_car(Car);

vector<string> split_date(string);