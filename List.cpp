#include <iostream>
#include <vector>
using namespace std;
class ArrayList {
public:
	ArrayList(int c) {
		cap = c;
		size = 0;
	
		arr = new int[cap];
	}
	void insertAt(int p, int item) {
		if (size == cap || p<0 || p>size) return;
		for (int i = size - 1; i >= p; i--)
			arr[i + 1] = arr[i];
		arr[p] = item;
		size++;
		
	}
	void Delete(int p) {
		if (size == 0 || p<0 || p > size) return;
		for (int i = p; i < size - 1; i++) {
			arr[i] = arr[i+1];
		}
		size--;
	}
private:
	int cap;
	int size;
	int* arr;

};

struct Node {
	int val;
	Node* next;
};

class LinkedList {
public:
	LinkedList() {
		head = nullptr;
	}
	void InsertAfter(Node* p, int item) {
		if (p == nullptr) return;
		Node* newNode = new Node();
		newNode->val = item;
		newNode->next = p->next;
		p->next = newNode;
	}
	void InsertAt(int item, int k) {
		if (k < 0) return;
		Node* newNode = new Node();
		newNode->val = item;
		if (k == 0) {
			newNode->next = head;
			head = newNode;
			return;
		}
		Node* cur = head;
		int pos = 0;
		while (cur && pos < k - 1) {
			cur = cur->next;
			pos++;
		}
		if (cur == nullptr) {
			delete newNode;
			return;
		}
		newNode->next = cur->next;
		cur->next = newNode;
	}
	void deleteAfter(Node* p) {
		if (!p || !p->next) return;
		Node* toDelete = p->next;
		p->next = toDelete->next;
		delete toDelete;
	}
private:
	Node* head;
};

class LoopedLinkedList {
public:
	LoopedLinkedList() {
		start = nullptr;
		end = nullptr;
	}
	void InsertRight(int item) {
		Node* newNode = new Node();
		newNode->val = item;
		if (!start) {
			start = end = newNode;
			newNode->next = newNode;
		}
		else {
			newNode->next = start;
			end->next = newNode;
			end = newNode;

		}
	}
	void InsertLeft(int item) {
		Node* newNode = new Node();
		newNode->val = item;
		if (!start) {
			start = end = newNode;
			newNode->next = newNode;
			return;
		}
		newNode->next = start;
		end->next = newNode;
		start = newNode;
	}
	void ClearList() {
		if (!start) return;
		Node* cur = start->next;
		Node* tmp;
		while (cur!=start) {
			tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		delete start;
		start = nullptr;
		end = nullptr;
	}
private:
	Node* start, * end;
};

struct DoubleNode {
	int val;
	DoubleNode* next;
	DoubleNode* prev;
};
class DoubleLinkedList {
public:
	DoubleLinkedList() {
		head = nullptr;
	}
	bool isEmpty() {
		if (!head) return true;
		return false;
	}
	void InsertRight(DoubleNode* P, int item) {
		if (!P) return;
		DoubleNode* newNode = new DoubleNode();
		newNode->prev = P;
		newNode->next = P->next;
		if (P->next) {
			P->next->prev = newNode;
		}
		P->next = newNode;
 	}
	void Delete(DoubleNode* P) {
		if (!P) return;
		if (P == head) {
			head = P->next;
		}
		if(P->prev)
		   P->prev->next = P->next;
		if(P->next)
		   P->next->prev = P->prev;
		delete P;
	}
private:
	DoubleNode* head;
};

template <class T>
struct NodeTemplate {
	T val;
	NodeTemplate<T>* next;
};
template <class T>
class List {
public:
	List() {
		head = nullptr;
		size = 0;
	} 
	List(const List& a) {
		if (!a.head) {
			head = nullptr;
			size = 0;
			return;
		}
		head = new NodeTemplate<T>();
		head->val = a.head->val;
		NodeTemplate<T>* curNew = head;
		NodeTemplate<T>* curOld = a.head->next;
		while (curOld) {
			NodeTemplate<T>* newNode = new NodeTemplate<T>();
			newNode->val = curOld->val;
			newNode->next = nullptr;
			curNew->next = newNode;
			curNew = newNode;
			curOld = curOld->next;
		}
		size = a.size;
	}
	~List() {
		NodeTemplate<T>* cur = head;
		NodeTemplate<T>* tmp;
		while (cur) {
			tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		head = nullptr;
		size = 0;
	}

	bool isEmpty() const {
		return size == 0;
	}
	int getLenght() const {
		return size;
	}
	NodeTemplate<T>* GetFirst() const {
		return head;
	}
	void InsertAfter(Node<T>* p, T item) {
		if (!p) return;
		NodeTemplate<T>* newNode = new NodeTemplate<T>();
		newNode->val = item;
		newNode->next = p->next;
		p->next = newNode;
		size++;
	}
	void insertAt(int n, T item) {
		if (n < 0 || n > size) return;
		NodeTemplate<T>* newNode = new NodeTemplate<T>();
		newNode->val = item;
		if (n == 0) {
			newNode->next = head;
			head = newNode;
		}
		else {
			NodeTemplate<T>* cur = head;
			for (int i = 0; i < n - 1; i++)
				cur = cur->next;
			newNode->next = cur->next->next;
			cur->next = newNode;
		}
		size++;
	}
	void DeleteAfter(Node<T>* p) {
		if (!p || !p->next) return;
		NodeTemplate<T>* tmp = p->next;
		p->next = tmp->next;
		delete tmp;
		size--;
	}
	void DeleteAt(int n) {
		if (n < 0 || n>=size) return;
		if (n == 0) {
			NodeTemplate<T>* tmp = head;
			head = head->next;
			delete tmp;
			size--;
			return;
		}
		NodeTemplate<T>* cur = head;
		for (int i = 0; i < n-1; i++) {
			cur = cur->next;
		}
		NodeTemplate<T>* tmp = cur->next;
		if (tmp) {
			cur->next = tmp->next;
			delete tmp;
			size--;
		}
	}
	T& GetData(Node<T>* p) {
		return p->val;
	}
private:
	NodeTemplate<T>* head;
	int size;
};


class CircularList {
public:
	CircularList() {
		head = nullptr;
		size = 0;
	}
	void insertEnd(int n) {
		Node* newNode = new Node();
		newNode->val = n;
		if (!head) {
			head = newNode;
			newNode->next = head;
			return;
		}
		Node* cur = head;
		while (cur->next != head) {
			cur = cur->next;
		}
		cur->next = newNode;
		newNode->next = head;
	}
	void deleteAfter(Node* prev) {
		if (!prev || !prev->next) return;
		Node* tmp = prev->next;
		prev->next = tmp->next; 
		if (tmp == head)
			head = tmp->next;
		delete tmp;
		size--;
	}
	int Josephus(int k) {
		if (!head) return -1;
		Node* cur = head;
		while (size > 1) {
			for (int i = 1; i < k - 1; i++)
				cur = cur->next;
			deleteAfter(cur);
			cur = cur->next;
		}
		return head->val;
	}
private:
	Node* head;
	int size;
};
struct NodePol {
	int coef;
	int exp;
	NodePol* next;
};
class polynom {
public:
	polynom() {
		head = nullptr;
	}
	void insert(int coef, int exp) {
		NodePol* newNode = new NodePol{ coef,exp,nullptr };
		if (!head || head->exp < exp) {
			newNode->next = head;
			head = newNode;
			return;
		}
		NodePol* cur = head;
		NodePol* prev = nullptr;
		while (cur && cur->exp > exp) {
			prev = cur;
			cur = cur->next;
		}
		if (cur && cur->exp == exp) {
			cur->coef += coef;
			delete newNode;
		}
		else {
			newNode->next = cur;
			if (prev) prev->next = newNode;
		}
	}
	void print() {
		NodePol* cur = head;
		while (cur) {
			cout << cur->coef << "x^" << cur->exp;
			if (cur->next) cout << "+";
			cur = cur->next;
		}
		cout << endl;
	}
	static polynom add(polynom& p1, polynom& p2) {
		polynom res;
		NodePol* a = p1.head;
		NodePol* b = p2.head;
		while (a && b) {
			if (a->exp > b->exp) {
				res.insert(a->coef, a->exp);
				a = a->next;
			}
			else if (a->exp < b->exp) {
				res.insert(b->coef, b->exp);
				b = b->next;
			}
			else {
				res.insert(a->coef + b->coef, a->exp);
				a = a->next;
				b = b->next;
			}
		}
		while (a) { res.insert(a->coef, a->exp); a = a->next; }
		while (b) { res.insert(b->coef, b->exp); b = b->next; }

		return res;
	}
private:
	NodePol* head;
};
int main() {
	int n, k;
	cin >> n >> k;
	CircularList c1;
	for (int i = 0; i <= n; i++)
		c1.insertEnd(i);
	int survivor = c1.Josephus(k);
	cout << survivor << endl;
	return 0;
}
