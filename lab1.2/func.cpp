#include "func.h"
using namespace std;

string enter_file_mode() {
    string file_mode;

    cout << "Do you want to overwrite the file or append input to it? Enter w or a:\n";
    cin >> file_mode;

    while (file_mode != "w" and file_mode != "a") {
        cout << "Incorrect input. Enter 'w' or 'a'." << endl;
        cout << "Do you want to overwrite the file or append input to it? Enter w or a:\n";
        cin >> file_mode;
    }

    return file_mode;
}

void create_fist_file(string file_name, int n, string mode) {
    ofstream file;

    if (mode == "w") {
        file.open(file_name, ios::binary);
    }
    else {
        file.open(file_name, ios::binary | ios::app);
    }

    Car car;
    cin.ignore();

    string s = "";

    for (int i = 0; i < n; ++i) {
        cout << "Car " << i + 1 << "\n";
        cout << "Enter the name of the car: ";
        getline(cin, s);
        strcpy(car.name, s.c_str());
        cout << "Enter the date when this car was released in such format MM.YYYY: ";
        getline(cin, s);
        strcpy(car.release_date, s.c_str());
        cout << "Enter the sale start date in such format MM.YYYY: ";
        getline(cin, s);
        strcpy(car.sell_date, s.c_str());
        file.write((char*)&car, sizeof(Car));
    }

    file.close();
}

void output_file(string file_name) {
    Car car;
    ifstream file(file_name, ios::binary);

    cout << "----------------------------------------------------------------------\n";
    while (file.read((char*)&car, sizeof(Car))) {
        output_car(car);
    }
    cout << "----------------------------------------------------------------------\n";

    file.close();
}

void create_list_recent_cars(string file_name1, string file_name2, int current_month, int current_year) {
    Car car;
    vector<Car> car_list;
    ifstream file_1(file_name1, ios::binary);

    while (file_1.read((char*)&car, sizeof(Car))) {
        car_list.push_back(car);
    }

    file_1.close();

    vector<string> month_year;
    vector<Car> recent_cars;
    int sell_month, sell_year;

    for (Car c : car_list) {
        month_year = split_date(c.sell_date);
        sell_month = stoi(month_year[0]);
        sell_year = stoi(month_year[1]);
        if (sell_month == current_month && sell_year == current_year) {
            recent_cars.push_back(c);
        }
    }

    ofstream file_2(file_name2, ios::binary);

    for (Car c : recent_cars) {
        file_2.write((char*)&c, sizeof(Car));
    }

    file_2.close();
}

void output_worn_cars(string file_name) {
    Car car;
    vector<Car> car_list;
    ifstream file(file_name, ios::binary);

    while (file.read((char*)&car, sizeof(Car))) {
        car_list.push_back(car);
    }

    file.close();

    vector<Car> worn_cars;
    vector<string> month_year_sell, month_year_release;
    int sell_month, sell_year, release_month, release_year, delta_year, delta_month;

    for (Car c : car_list) {
        month_year_sell = split_date(c.sell_date);
        sell_month = stoi(month_year_sell[0]);
        sell_year = stoi(month_year_sell[1]);
        month_year_release = split_date(c.release_date);
        release_month = stoi(month_year_release[0]);
        release_year = stoi(month_year_release[1]);
        delta_year = sell_year - release_year;
        delta_month = sell_month - release_month;
        if (delta_year > 1 || (delta_month > 0 && delta_year == 1)) {
            worn_cars.push_back(c);
        }
    }

    cout << "Worn cars(more than one year):" << endl;
    cout << "----------------------------------------------------------------------\n";
    for (Car c : worn_cars) {
        output_car(c);
    }
    cout << "----------------------------------------------------------------------\n";
}

void output_car(Car car) {
    cout << "Car name: " << car.name << ", release date: " << car.release_date << ", sell start date: " << car.sell_date << "\n";
}

vector <string> split_date(string str) {
    vector <string> month_year;
    string temp;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '.') {
            month_year.push_back(temp);
            temp = "";
        }
        else {
            temp += str[i];
        }
    }

    month_year.push_back(temp);

    return month_year;
}