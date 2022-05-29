#include "MyTree.h"
using namespace std;

void MyTree::insertL(string key) {
	if (this->Left == NULL) this->Left = new MyTree(key);
	else {
		MyTree* p = new MyTree(key);
		p->Left = this->Left;
		this->Left = p;
	}
}

void MyTree::insertR(string key) {
	if (this->Right == NULL) this->Right = new MyTree(key);
	else {
		MyTree* p = new MyTree(key);
		p->Right = this->Right;
		this->Right = p;
	}
}

bool MyTree::isLeave() {
	if (this->Left == NULL && this->Right == NULL) return true;
	return false;
}