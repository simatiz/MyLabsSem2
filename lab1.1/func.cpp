#include "func.h"

void input_file(string path) {
	string line;
	ofstream fout;
	fout.open(path);
	if (fout.is_open())
	{
		cout << "Enter your strings:" << endl;
		getline(cin, line);
		while (line[0] > 31) {
			fout << line << endl;
			getline(cin, line);
		}
		fout.close();
	}
	else {
		cout << "Error";
	}
}

void output_file(string path) {
	string line;
	ifstream fin;
	fin.open(path);
	if (fin.is_open()) {
		cout << endl << path << " file content:" << endl;
		while (!fin.eof()) {
			getline(fin, line);
			cout << line << endl;
		}
		fin.close();
	}
	else {
		cout << "Error";
	}
}

vector<string> split(string line) {
	vector<string> res;
	string slice = "";
	char sep = ' ';
	line += sep;
	for (int i = 0; i < int(line.length()); i++) {
		if (line[i] == sep) {
			if (slice.length() > 0) res.push_back(slice);
			slice = "";
		}
		else slice += line[i];
	}
	return res;
}

void process_file(string path_to_first_file, string path_to_second_file, int n) {
	string line;
	ofstream fout;
	ifstream fin;
	vector<string> words;
	vector<string> res_words;
	vector<string> undivided_words;
	fin.open(path_to_first_file);
	fout.open(path_to_second_file);
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, line);
			undivided_words = split(line);
			words.insert(words.end(), undivided_words.begin(), undivided_words.end());
		}
		for (int i = 0; i < words.size(); i++) {
			if (count(words.begin(), words.end(), words[i]) < n) {
				res_words.push_back(words[i]);
			}
		}
		sort(res_words.begin(), res_words.end(), [](const string& a, const string& b) { return a.length() > b.length(); });
		for (int i = 0; i < res_words.size(); i++) {
			fout << res_words[i] << endl;
		}
		fin.close();
		fout.close();
	}
	else {
		cout << "Error";
	}
}