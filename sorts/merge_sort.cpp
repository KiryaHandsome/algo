#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int>& v, int f, int mid, int l)
{
    int sz1 = mid - f + 1, sz2 = l - mid;
    vector<int> L(sz1 + 1), R(sz2 + 1);
    for (int i = 0; i < sz1; i++)
    {
        L[i] = v[f + i];
    }
    for (int i = 0; i < sz2; i++)
    {
        R[i] = v[mid + i + 1];
    }

    L[sz1] = INT_MAX;
    R[sz2] = INT_MAX;

    int j = 0, k = 0;
    for (int i = f; i <= l; i++)
    {
        if (L[j] <= R[k])
        {
            v[i] = L[j++];
        }
        else
        {
            v[i] = R[k++];
        }
    }
}

void mergeSort(vector<int>& v, int f, int l)
{
    if (f < l)
    {
        int mid = (f + l) / 2;
        mergeSort(v, f, mid);
        mergeSort(v, mid + 1, l);
        merge(v, f, mid, l);
    }
}

void mergeSort(vector<int>& v)
{
    mergeSort(v, 0, v.size() - 1);
}

int main()
{
    vector<int> v;
    v.reserve(1e7);
    for (int i = 0; i < 1e7; i++) {
        v.push_back(rand());
    }
    auto t1 = clock();
    mergeSort(v);
    auto t2 = clock();
    cout << t2 - t1;
}