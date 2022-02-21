#include <iostream>
#include "func.h"
using namespace std;

int main() {
	int n;
	string path_to_first_file = "text.txt";
	string path_to_second_file = "text_res.txt";

	input_file(path_to_first_file);

	cout << "Enter max word count: ";
	cin >> n;

	output_file(path_to_first_file);
	process_file(path_to_first_file, path_to_second_file, n);
	output_file(path_to_second_file);
}