#include <vector>
#include <iostream>

using namespace std;

void insertionSort(vector<int>& v)
{
    size_t size = v.size();
    for (int j = 1; j < size; j++)
    {
        auto key = v[j];
        int i = j - 1;
        while (i >= 0 && v[i] > key)
        {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;
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
    insertionSort(v);
    auto t2 = clock();
    cout << t2 - t1;
}