#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	int leafIdx;

	Node(int v, int idx = -1) : val(v), left(nullptr), right(nullptr), leafIdx(idx) {};
};
Node* buildTournament(int a[], int l, int r) {
	if (l == r)
		return new Node(a[l], l);
	int mid = (l + r) / 2;
	Node* left = buildTournament(a, l, mid);
	Node* right = buildTournament(a, mid + 1, r);
	Node* parent = new Node(min(left->val, right->val));
	parent->left = left;
	parent->right = right;
	return parent;
}
void removeMin(Node* node, int a[]) {
	if (!node) return;
	if (node->leafIdx != -1) {
		a[node->leafIdx] = INT_MAX;
		node->val = INT_MAX;
		return;
	}
	if (node->left->val <= node->right->val)
		removeMin(node->left, a);
	else
		removeMin(node->right, a);
	node->val = min(node->left->val, node->right->val);
}
void tournamentSort(int a[], int n) {
	Node* root = buildTournament(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << root->val << " ";
		removeMin(root, a);
	}
	cout << endl;
}

void deleteTree(Node* root) {
	if (!root) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}
int main() {
	int a[] = { 4,2,5,7,8,12,3 };
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	tournamentSort(a, n);
	return 0;
}
