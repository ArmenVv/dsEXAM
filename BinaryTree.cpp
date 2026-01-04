#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class BinaryTree {
public:
	BinaryTree(int c) {
		cap = c;
		size = 0;
		arr = new int[cap];
	}
	void insert(int x) {
		if (size == cap) return;
		arr[size] = x;
		size++;
	}
	int getLeft(int i) {
		return 2 * i + 1;
	}
	int getRight(int i) {
		return 2 * i + 2;
	}
	int getParent(int i) {
		return (i - 1) / 2;
	}
	void print() {
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
private:
	int* arr;
	int size;
	int cap;
};

struct treeNode {
	int val;
	treeNode* left, * right;
	treeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class binaryTree {
public:
	binaryTree() {
		root = nullptr;
	}
	void insertLeft(treeNode *parent, int x) {
		if (!parent || parent->left) return;
		treeNode* newNode = new treeNode(x);
		parent->left = newNode;
	}
	void insertRight(treeNode* parent, int x) {
		if (!parent || parent->right) return;
		treeNode* newNode = new treeNode(x);
		parent->right = newNode;
	}
	treeNode* getRoot() { return root; }
	void setRoot(int x) {
		if (!root) root = new treeNode(x);
	}
private:
	treeNode* root;
};

template <typename T>
struct treeNode {
	T val;
	treeNode* left, * right;
	treeNode(const T& x) : val(x), left(nullptr), right(nullptr) {};
};

template <typename T>
class binaryTree {
public:
	binaryTree() {
		root = nullptr;
	}
	void insertLeft(const T& x) {
		if (!root || root->left) return;
		root->left = treeNode<T>(x);
	}
	void insertRight(const T& x) {
		if (!root || root->right) return;
		root->right = treeNode<T>(x);
	}
	treeNode* find(treeNode<T>* root, T x) {
		if (!root) return nullptr;
		if (root->val == x) return node;
		treeNode* leftRes = find(root->left, x);
		if (leftRes) return leftRes;
		return find(node->right, x);
	}
	void deleteSubtree(treeNode<T>*& node) {
		if (!node) return;
		if(node->left) deleteSubtree(node->left);
		if (node->right) deleteSubtree(node->right);
		delete node;
		node = nullptr;
	}
	int height(treeNode<T>* root) {
		if (!root) return 0;
		return 1 + max(height(root->left), height(root->right));
	}
	int coundNodes(treeNode<T>* root) {
		if (!node) return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
	void clear(treeNode<T>* root) {
		deleteSubtree(root);
	}
	void inorderRecursive(treeNode<T>* root) {
		if (!root) return;
		inorderRecursive(root->left);
		cout << root->val << " "; 
		inorderRecursive(root->right);
	}
	void inorderIterative(treeNode<T>* root) {
		stack<treeNode<T>>st;
		treeNode<T>* cur = root;
		while (cur || !st.empty()) {
			while (cur) {
				st.push(cur);
				cur = cur->left;
			}
			cur = st.top();
			st.pop();
			cout << cur->val << " ";
			cur = cur->right;
		}
	}
	void preorderRecursive(treeNode<T>* root) {
		cout << root->val << " ";
		preorderRecursive(root->left);
		preorderRecursive(root->right);
	}
	void preorderIterative(treeNode<T>* root) {
		stack<treeNode<T>*> st;
		st.push(root);
		while (!st.empty()) {
			treeNode<T>* cur = st.top();
			st.pop();
			cout << cur->val << " ";
			if(cur->right) st.push(cur->right);
			if(cur->left) st.push(cur->right);
		}
	}
	void postorderRecursive(treeNode<T>* root) {
		preorderRecursive(root->left);
		preorderRecursive(root->right);
		cout << root->val << " ";
	}
	void postorderIterative(treeNode<T>* root) {
		stack<treeNode<T>*> st1;
		stack<treeNode<T>*> st2;
		st1.push(root);
		while (!st1.empty()) {
			treeNode<T>* cur = st1.top();
			st1.pop();
			st2.push(cur);
			if (cur->left)
				st1.push(cur->left);
			if (cur->right)
				st2.push(cur->right);
		}
		while (!st2.empty()) {
			cout << st2.top()->val << " ";
			st2.pop()
		}
	}
private:
	treeNode<T>* root;
};
