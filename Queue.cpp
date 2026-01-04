#include <iostream>
using namespace std;

class Queue {
public:
	Queue(int capacity) {
		cap = capacity;
		arr = new int[cap];
		front = 0;
		rear = -1;
		count = 0;
	}
	bool isEmpty() { return count == 0; }
	void Insert(int x) {
		if (count == cap)
			resize();
		rear = (rear + 1) % cap;
		arr[rear] = x;
		count++;
	}
	void Delete() {
		if (count == 0) return;
		front = (front + 1) % cap;
		count--;
	}
	int getFirst() {
		return arr[front];
	}
	void clearQueue() {
		count = 0;
		front = 0;
		rear = -1;
	}
private:
	int* arr;
	int front;
	int rear;
	int cap;
	int count;
	
	void resize() {
		int newCap = 2 * cap;
		int* newArr = new int[newCap];
		for (int i = 0; i < count; i++)
			newArr[i] = arr[(front + i) % cap];
		delete[]arr;
		arr = newArr;
		cap = newCap;
		front = 0;
		rear = count - 1;
	}
};

struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
};
class Queue {
public:
	Queue() {
		front= nullptr;
		rear = nullptr;
		size = 0;
	}
	bool isEmpty() { return size == 0; }
	void Insert(int x) {
		Node* newNode = new Node(x);
		if (isEmpty()) {
			front = rear = newNode;
			size++;
			return;
		}
		rear->next = newNode;
		rear = newNode;
		size++;
	}
	void Delete() {
		if (isEmpty()) return;
		Node* tmp = front;
		front = front->next;
		delete tmp;
		size--;

		if (isEmpty()) rear = nullptr;
	}
	void clearQueue() {
		while (!isEmpty()) {
			Delete();
		}
	}
private:
	Node* front,*rear;
	int size;
};

template <typename T>
struct Node {
	T val;
	Node* next;
	Node(const T& x) : val(x), next(nullptr) {};
};
template <typename T>
class Queue {
public:
	Queue(){
		front = rear = nullptr;
		size = 0;
	}
	bool isEmpty() {
		return size == 0;
	}
	void Insert(const T&x) {
		Node <T>* newNode = new Node<T>(x);
		if (isEmpty()) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
		size++;
	}
	void Delete() {
		if (isEmpty()) return;
		Node <T>* tmp = front;
		front = front->next;
		delete tmp;
		size--;
		if (isEmpty()) rear = nullptr;
	}
	T getFirst() {
		if (isEmpt()) throw std::runtime_error("Queue is empty!");
		return front->val;
	}

private:
	Node <T>* front;
	Node <T>* rear;
	int size;

};
