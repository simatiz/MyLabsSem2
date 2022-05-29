#include "func.h"
#include <stack>
#include <string>
using namespace std;

vector<string> rebuiltForm(string formula) {
	vector<string> vect;
	int pos = 0;

	while (formula.find(' ') != string::npos) {
		pos = formula.find(' ');
		vect.push_back(formula.substr(0, pos));
		formula = formula.substr(pos + 1);
	}

	vect.push_back(formula);
	return vect;
}

MyTree* formTree(vector<string> formula) {
	stack<MyTree*> myStack;
	MyTree* Tree = new MyTree("");
	myStack.push(Tree);
	MyTree* curTree = Tree;
	string determ = "+-*/";

	for (string i : formula) {
		if (i == "(") {
			curTree->insertL("");
			myStack.push(curTree);
			curTree = curTree->getLeft();
		}
		else if (i == ")") {
			curTree = myStack.top();
			myStack.pop();
		}
		else if (determ.find(i) != string::npos) {
			curTree->setRoot(i);
			curTree->insertR("");
			myStack.push(curTree);
			curTree = curTree->getRight();
		}
		else if (determ.find(i) == string::npos) {
			curTree->setRoot(i);
			curTree = myStack.top();
			myStack.pop();
		}
	}

	return Tree;
}

void outputTree(const string& prefix, MyTree* tree, bool isLeft) {
	if (tree != NULL) {
		cout << prefix;
		cout << "'__";
		cout << tree->getRoot() << "\n";

		outputTree(prefix + (isLeft ? "|   " : "    "), tree->getLeft(), true);
		outputTree(prefix + (isLeft ? "|   " : "    "), tree->getRight(), false);
	}
}

void changeTree(MyTree* tree) {
	if (tree) {
		cnangeTree2(tree);
		changeTree(tree->getLeft());
		changeTree(tree->getRight());
	}
}

void cnangeTree2(MyTree* tree) {
	MyTree* left = tree->getLeft();
	MyTree* right = tree->getRight();
	string plus1 = "", plus2 = "", mult = "", symb = "";

	if (tree->getRoot() == "*") {
		if (left->isLeave()) mult = left->getRoot();
		if (right->isLeave()) mult = right->getRoot();
	}
	if (mult != "") {
		if (left->getRoot() == "+" || left->getRoot() == "-") {
			symb = left->getRoot();
			if (left->getLeft()->isLeave()) plus1 = left->getLeft()->getRoot();
			if (left->getRight()->isLeave()) plus2 = left->getRight()->getRoot();
		}

		if (right->getRoot() == "+" || right->getRoot() == "-") {
			symb = right->getRoot();
			if (right->getLeft()->isLeave()) plus1 = right->getLeft()->getRoot();
			if (right->getRight()->isLeave()) plus2 = right->getRight()->getRoot();
		}
	}
	if (mult != "" && plus1 != "" && plus2 != "") {
		string formula = "( ( " + plus1 + " * " + mult + " ) " + symb + " ( " + plus2 + " * " + mult + " ) )";
		string oldFormula = "( ( " + plus1 + " " + symb + " " + plus2 + " ) * " + mult + " )";
		cout << oldFormula << " = " << formula << "\n";

		vector<string> vect = rebuiltForm(formula);
		MyTree* newTree = new MyTree("");
		newTree = formTree(vect);

		tree->setRoot(symb);
		tree->setRight(newTree->getRight());
		tree->setLeft(newTree->getLeft());
	}
}