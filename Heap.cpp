#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Heap {
public:
	Heap() {
		size = 0;
		cap = 10;
	}
	bool isEmpty() {
		return size == 0;
	}
	void Insert(int x) {
		if (size == cap) cout << "Heap is full";
		else {
			arr.push_back(x);
			size++;
			int place = size - 1;
			int parent = (place - 1) / 2;

			while (place > 0 && arr[place] > arr[parent])
			{
				int tmp = arr[place];
				arr[place] = arr[parent];
				arr[parent] = tmp;
				place = parent;
				parent = (place-1) / 2;
			}
		}
	}
	void heapDelete() {
		if (isEmpty()) return;
		arr[0] = arr[--size];
		arr.pop_back();
		heapRebuild(0);
	}
private:
	vector<int>arr;
	int size;
	int cap;
	void heapRebuild(int root) {
		int childL = 2 * root + 1;
		if (childL < size) {
			int childR = childL + 1;
			if (childR<size && arr[childR] > arr[childL])
				childL = childR;
			if (arr[root] < arr[childL]) {
				int tmp = arr[root];
				arr[root] = arr[childL];
				arr[childL] = tmp;
				heapRebuild(childL);
			}
		}
	}
};
