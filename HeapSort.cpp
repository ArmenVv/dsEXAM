#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Heap {
public:
    Heap() {
        size = 0;
        cap = 10;
    }
    void insert(int x) {
        if (size == 0) {
            arr.push_back(x);
            size++;
        }
        else if (cap == size)
            return;
        else {
            arr.push_back(x);
            size++;
            int place = size - 1;
            int parent = (place - 1) / 2;
            while (place > 0 && arr[place] > arr[parent]) {
                swap(arr[place], arr[parent]);
                place = parent;
                parent = (place - 1) / 2;
            }
        }
    }
    void heapSort(vector<int>&arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
private:
    vector<int>arr;
    int size;
    int cap;

    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left]>arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
};
