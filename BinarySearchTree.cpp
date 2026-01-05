#include <iostream>
using namespace std;

struct treeNode {
	int val;
	treeNode* left, * right;

	treeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class BinarySearchTree {
public:
	BinarySearchTree() {
		root = nullptr;
		size = 0;
	}
	void Insert(int x) {
		treeNode* t = root, * parent = nullptr, * newNode;
		while (t) {
			parent = t;
			if (x < t->val)
				t = t->left;
			else
				t = t->right;
		}
		newNode = new treeNode(x);
			if (!parent)
				root = newNode;
			else if (x < parent->val)
				parent->left = newNode;
			else
				parent->right = newNode;
		
		size++;
	}
	treeNode* Search(int x, treeNode*& parent) const{
		treeNode* t = root;
		parent = nullptr;
		while (t) {
			if (x == t->val)
				break;
			else {
				parent = t;
				if (x < t->val)
					t = t->left;
				else
					t = t->right;
			}
		}
		return t;
	}
	void Delete(int x) {
		treeNode* parent = nullptr;
		treeNode *toDelete = Search(x, parent);
		if (!toDelete) return;
		if (!toDelete->left && !toDelete->right) {
			if (!parent) root = nullptr;
			else if (parent->left == toDelete)
				parent->left = nullptr;
			else
				parent->right = nullptr;
			delete toDelete;
		}
		if (toDelete->left && !toDelete->right) {
			treeNode* tmp = toDelete->left;
			if (!parent)
				root = tmp;
			else if (parent->left = toDelete)
				parent->left = tmp;
			else
				parent->right = tmp;
			delete tmp;
		}
		if (!toDelete->left && toDelete->right) {
			treeNode* tmp = toDelete->right;
			if (!parent) root = tmp;
			else if (parent->left == toDelete)
				parent->left = tmp;
			else
				parent->right = tmp;
			delete tmp;
		}
		if (toDelete->left && toDelete->right) {
			treeNode* predParent = toDelete;
			treeNode* pred = toDelete->left;
			while (pred->right) {
				predParent = pred;
				pred = pred->right;
			}
			toDelete->val = pred->val;
			if (predParent->right == pred)
				predParent->right = pred->left;
			else
				predParent->left = pred->left;
			delete pred;
		}

	}
private:
	treeNode* root;
	int size;
};
