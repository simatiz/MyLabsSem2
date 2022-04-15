#include "operations.h"
using namespace std;

vector<Product> get_product_list(int n) {
    string name, date;
    vector<Product> product_list;

    cin.ignore();

    for (int i = 0; i < n; ++i) {
        cout << "Enter the product name: ";
        getline(cin, name);

        cout << "Enter the release date in such format MM-DD-YYYY:" << endl;
        getline(cin, date);

        while (!is_valid_date(date)) {
            cout << "Incorrect input for the date. Please enter a valid date:" << endl;
            getline(cin, date);
        }

        Date release_date(date);

        cout << "Enter the expire date in such format MM-DD-YYYY:" << endl;
        getline(cin, date);

        while (!is_valid_date(date)) {
            cout << "Incorrect input for the date. Please enter a valid date:" << endl;
            getline(cin, date);
        }

        Date expire_date(date);

        while (!is_earlier(release_date, expire_date)) {
            cout << "Expire date should be later than release date. Please enter a valid date:" << endl;
            getline(cin, date);
            expire_date = Date(date);
        }

        product_list.emplace_back(Product(name, release_date, expire_date));
    }

    return product_list;
}


vector<Product> get_expired_products(const string& date, const vector<Product>& products) {
    vector<Product> exp_products;
    Date current_date(date);

    for (const Product& pr : products) {
        Date expire_date = pr.get_expire_date();
        if (is_earlier(expire_date, current_date)) {
            exp_products.push_back(pr);
        }
    }

    return exp_products;
}



bool is_valid_date(const string& s) {
    bool is_valid = false;
    char delim = '-';

    if (s.length() == 10) {
        if (s[2] == s[5] && s[2] == delim) {
            vector <string> strings = split(s, delim);
            int i = 0;
            bool is_num = true;

            while (i < strings.size() && is_num) {
                is_num = is_number(strings[i]);
                i++;
            }

            if (is_num) {
                int month = stoi(strings[0]);
                int year = stoi(strings[2]);
                bool is_month = month > 0 && month <= 12;
                bool is_year = year >= 1000 and year < 10000;

                if (is_month && is_year) {
                    int day = stoi(strings[1]);

                    if (day > 0 and day <= 31) {
                        vector <int> days_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
                        bool is_fourth = !(year % 4);

                        if (is_fourth) {
                            days_month[1] = 29;
                        }

                        if (day <= days_month[month - 1]) {
                            is_valid = true;
                        }
                    }
                }
            }
        }

    }

    return is_valid;
}


bool is_number(string str) {
    int i = 0;
    bool is_num = true;

    while (i < str.length() && is_num) {
        if (!isdigit(str[i])) is_num = false;
        i++;
    }

    return is_num;
}

vector<string> split(string str, char delim = ' ') {
    vector<string> words;
    string temp_str;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == delim || i == str.length() - 1) {
            if (str[i] == delim) {
                words.push_back(temp_str);
                temp_str = "";
            }
            else {
                temp_str += str[i];
                if (!temp_str.empty()) words.push_back(temp_str);
            }
        }
        else {
            temp_str += str[i];
        }
    }

    return words;
}

void output_products(const vector<Product>& products) {
    if (products.empty()) cout << "The list is empty.";

    for (Product pr : products) {
        pr.print();
    }
}

bool is_earlier(const Date& date_1, const Date& date_2) {
    bool check = true;
    int days_1 = date_1.get_day();
    int days_2 = date_2.get_day();
    int months_1 = date_1.date_in_months();
    int months_2 = date_2.date_in_months();

    if (months_1 > months_2 || (months_1 == months_2 && days_1 > days_2)) {
        check = false;
    }

    return check;
}