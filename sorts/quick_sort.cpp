#include <vector>
#include <iostream>
#include <algorithm>


void quicksort(std::vector<int>& v, int l, int r);

int partition(std::vector<int>& v, int l, int r);



void quicksort(std::vector<int>& v)
{
    quicksort(v, 0, (int)v.size() - 1);
}

void quicksort(std::vector<int>& v, int l, int r)
{
    if (l < r) {
        int q = partition(v, l, r);
        quicksort(v, l, q - 1);
        quicksort(v, q + 1, r);
    }
}

int partition(std::vector<int>& v, int l, int r)
{
    int x = v[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (v[j] <= x) {
            std::swap(v[j], v[++i]);
        }
    }
    std::swap(v[i + 1], v[r]);
    return i + 1;
}

void quicksort2(std::vector<int>& array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    if (j > low)
        quicksort(array, low, j);
    if (i < high)
        quicksort(array, i, high);
}

int main()
{
    std::vector<int> v{};
    v.reserve(1e7);
    for (int i = 0; i < 1e7; i++) {
        v.push_back(rand());
    }
    auto t1 = clock();
    std::sort(v.begin(), v.end());

    auto t2 = clock();
    std::cout << t2 - t1;


    /*for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ' ';
    }*/
}

