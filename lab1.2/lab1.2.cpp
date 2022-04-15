#include "func.h"
using namespace std;

int main() {
    int n, month, year;

    string file_1 = "cars_1.bin";
    string file_2 = "cars_2.bin";

    string file_mode = enter_file_mode();

    cout << "Enter the number of cars:" << endl;
    cin >> n;

    create_fist_file(file_1, n, file_mode);

    cout << "List of cars(first file):" << endl;
    output_file(file_1);

    cout << "Enter the month number:" << endl;
    cin >> month;

    cout << "Enter the year:" << endl;
    cin >> year;

    create_list_recent_cars(file_1, file_2, month, year);

    cout << "List of cars which started selling this month(second file):" << endl;
    output_file(file_2);

    output_worn_cars(file_1);

    return 0;
}