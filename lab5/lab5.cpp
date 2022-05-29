#include <string>
#include "func.h"
using namespace std;

int main() {
    // Examples:
    // ( ( 2 + 7 ) * 4 )
    // ( 6 - ( ( 7 + 0 ) * 9 ) )
    // ( ( 2 + ( ( 2 + 3 ) * 4 ) ) - ( 5 * ( 4 - 6 ) ) )

    string formula;
    cout << "Enter the formula, each operation is separated by brackets, characters are separated by spaces:\n";
    getline(cin, formula);

    vector<string> vect = rebuiltForm(formula);
    MyTree* tree = formTree(vect);

    cout << "\nStart tree:\n\n";
    outputTree("", tree, false);
    cout << "\n";

    changeTree(tree);
    cout << "\nFinal tree:\n\n";
    outputTree("", tree, false);

    delete tree;
}