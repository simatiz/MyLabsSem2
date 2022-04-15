#include "product.h"
#include "operations.h"
using namespace std;

int main() {
    int n;
    string current_date;

    cout << "Enter the number of products: ";
    cin >> n;

    vector<Product> product_list = get_product_list(n);

    cout << "Products:" << endl;
    output_products(product_list);

    cout << "Enter current date:" << endl;
    getline(cin, current_date);

    while (!is_valid_date(current_date)) {
        cout << "Incorrect date. Please enter a valid date:" << endl;
        getline(cin, current_date);
    }

    vector <Product> expired_products = get_expired_products(current_date, product_list);

    cout << "Expired products:" << endl;
    output_products(expired_products);

    return 0;
}