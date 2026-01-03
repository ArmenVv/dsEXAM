#include <iostream>
using namespace std;

class Stack {
public:
	Stack(int capacity = 4) {
		cap = capacity;
		arr = new int[cap];
		top = -1;
	}
	bool isEmpty() {
		return top == -1;
	}
	void push(int x) {
		if (top == cap - 1)
			resize();
		arr[++top] = x;
	}
	void pop() {
		if (isEmpty()) return;
		top--;
	}
	int getTop() {
		if (isEmpty())
			return -1;
		return arr[top];
	}
	int size() {
		return top + 1;
	}
	~Stack() {
		delete[]arr;
	}
private:
	int* arr;
	int cap;
	int top;

	void resize() {
		int newCap = 2 * cap;
		int* newArr = new int[newCap];
		for (int i = 0; i <= top; i++)
			newArr[i] = arr[i];
		delete[]arr;
		arr = newArr;
		cap = newCap;
	}
};

struct Node {
	int val;
	Node* next;
};

class Stack {
public:
	Stack() {
		top = nullptr;
	}
	bool isEmpty() {
		return top == nullptr;
	}
	void push(int x) {
		Node* newNode = new Node();
		newNode->val = x;
		newNode->next = top;
		top = newNode;
	}
	void pop() {
		if (isEmpty()) return;
		Node* tmp = top;
		top = top->next;
		delete tmp;
	}
	int peek() {
		if (isEmpty())
			return -1;
		return top->val;
	}
	~Stack() {
		while (!isEmpty())
			pop();
	}
private:
	Node* top;
};
template <typename T>
class Stack {
public:
	Stack(int capacity = 4) {
		cap = capacity;
		top = -1;
		arr = new T[cap];
	}
	bool isEmpty() const {
		return top == -1;
	}
	void push(const T& x) {
		if (top == cap - 1) {
			resize();
		}
		arr[++top] = x;
	}
	void pop() {
		if (isEmpty()) return;
		top--;
	}
	T& peek(){
		if (isEmpty()) throw runtime_error("Stack is full");
		return arr[top]
	}
	int size() {
		return top + 1;
	}
	~Stack() {
		delete[]arr;
	}
private:
	T* arr;
	int top;
	int cap;
	
	void resize() {
		int newCap = 2 * cap;
		T* newArr = new T[newCap];
		for (int i = 0; i <= top; i++)
			newArr[i] = arr[i];
		delete[] arr;
		arr = newArr;
		cap = newCap;
	}
};

#include <stack>
int priority(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}
string toPostfix(string expr) {
	stack<char>st;
	string res;
	for (char c : expr) {
		if (isdigit(c)) {
			res += c;
			res += ' ';
		}
		else if (c == '(') {
			st.push(c);
		}
		else if (c == ')') {
			while (!st.empty() && st.top() != '(') {
				res += st.top();
				res += ' ';
				st.pop();
			}
			st.pop();
		}
		else {
			while (!st.empty() && priority(st.top()) >= priority(c)) {
				res += st.top();
				res += ' ';
				st.pop();
			}
			st.push(c);
		}
	}
	while (!st.empty()) {
		res += st.top();
		res += ' ';
		st.pop();
	}
	return res;
}
