#include <vector>

using namespace std;

void selectionSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        swap(v[min], v[i]);
    }
}