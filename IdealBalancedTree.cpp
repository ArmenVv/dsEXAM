#include <iostream>
using namespace std;
const int indent = 6;
struct Node {
	int data;
	Node* left, * right;
};
int n;
typedef Node* PNode;
PNode root;
PNode Tree(int n) {
	PNode newNode;
	int x, nl, nr;
	if (n == 0) newNode = nullptr;
	else {
		nl = n / 2;
		nr = n - nl - 1;
		cin >> x;
		newNode = new Node;
		newNode->data = x;
		newNode->left = Tree(nl);
		newNode->right = Tree(nr);
	};
	return newNode;
}
PrintTree(PNode t, int level) {
	int i;
	if (!t) {
		PrintTree(t->right, level + 1);
		for (i = 1; i < indent * level; i++)
			cout << " ";
		cout << t->data << endl;
		PrintTree(t->left, level + 1);
	}
}
int main() {
	cin >> n;
	root = Tree(n);
	PrintTree(root, 0);
	return 0;
}
