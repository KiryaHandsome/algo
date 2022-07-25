#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void max_heapify(vector<int>& v, int heap_size, int idx)
{
    int l = idx * 2 + 1; //left
    int r = idx * 2 + 2; //right
    int largest = idx;
    if (l < heap_size && v[l] > v[largest]) {
        largest = l;
    }
    if (r < heap_size && v[r] > v[largest]) {
        largest = r;
    }

    if (largest != idx) {
        swap(v[idx], v[largest]);
        max_heapify(v, heap_size, largest);
    }
}

void build_max_heap(vector<int>& v)
{
    for (int i = v.size() / 2; i >= 0; i--) {
        max_heapify(v, v.size(), i);
    }
}

void heapSort(vector<int>& v)
{
    if (v.size() < 2) return;
    build_max_heap(v);
    for (int i = v.size() - 1; i > 0; i--) {
        swap(v[i], v[0]);
        max_heapify(v, i, 0);
    }
}

int main()
{
    vector<int> v;
    v.reserve(1e7);
    for (int i = 0; i < 1e7; i++) {
        v.push_back(rand());
    }
    auto t1 = clock();
    heapSort(v);
    //sort(v.begin(), v.end());
    auto t2 = clock();
    cout << t2 - t1;
}

//****statistics for 10^7 elements****//
// std::sort      - 2,546 sec.
// heapsort       - 6,378 sec.
// insertion sort - infinity
// mergesort      - 15,253 sec