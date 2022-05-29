#pragma once
#include <iostream>
using namespace std;
class MyTree {
	string key;
	MyTree* Left, * Right;

public:
	MyTree(string kluch) { key = kluch; Left = NULL; Right = NULL; }

	void insertL(string);
	void insertR(string);

	MyTree* getLeft() { return Left; }
	MyTree* getRight() { return Right; }

	void setRoot(string k) { key = k; }

	string getRoot() { return key; }

	bool isLeave();
	void setRight(MyTree* obj) { Right = obj; }
	void setLeft(MyTree* obj) { Left = obj; }
};