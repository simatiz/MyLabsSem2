#include "Square.h"
#include "input_operations.h"

int main() {
    int n, choice;
    double p, area, sum_squares_rectangles, sum_p_parallelograms;
    vector<int> coordinates;

    sum_squares_rectangles = 0;
    sum_p_parallelograms = 0;

    cout << "Enter the number of quadrangles to be created: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter 1 for parallelogram, 2 for rectangle, 3 for square: ";
        cin >> choice;
        cout << "Enter the coordinates for the figure in such format (x, y):\n";
        coordinates = input_points();

        if (choice == 1) {
            Parallelogram figure(coordinates);
            p = figure.get_perimeter();
            sum_p_parallelograms += p;
            cout << "The perimeter of the parallelogram is: " << p << "\n";
        }
        else if (choice == 2) {
            Rectangle figure(coordinates);
            area = figure.get_area();
            sum_squares_rectangles += area;
            cout << "The area of the rectangle is: " << area << "\n";
        }
        else {
            Square figure(coordinates);
            area = figure.get_area();
            sum_squares_rectangles += area;
            cout << "The area of the square is: " << area << "\n";
        }
    }
    cout << "The sum of the areas of all the squares and rectangles is: " << sum_squares_rectangles << "\n";
    cout << "The sum of the perimeters of all the parallelograms is: " << sum_p_parallelograms << "\n";
    return 0;
}