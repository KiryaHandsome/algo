#include <vector>
#include <stdexcept>
#include <iostream>
#include <queue>

template<class T>
class priority_queue
{
    using const_reference = const T&;
private:
    std::vector<T> v;
public:
    const_reference top() const {
        if (v.size() == 0) {
            throw std::out_of_range("queue is empty");
        }
        return v.front();
    }

    void pop()
    {
        if (v.size() == 0) {
            throw std::out_of_range("queue is empty");
        }
        v.front() = v.back();
        v.pop_back();
        max_heapify(0);
    }

    void push(const T& value) {
        v.push_back(value);
        size_t i = v.size() - 1;
        size_t par = parent(i);
        while (i > 0 && v[i] > v[par]) {
            std::swap(v[i], v[par]);
            i = par;
            par = parent(i);
        }
    }

    size_t size() const { return v.size(); }

private:
    void max_heapify(size_t idx)
    {
        size_t l = left(idx);
        size_t r = right(idx);
        size_t largest = idx, heap_size = v.size();
        if (l < heap_size && v[l] > v[largest]) {
            largest = l;
        }
        if (r < heap_size && v[r] > v[largest]) {
            largest = r;
        }

        if (largest != idx) {
            std::swap(v[idx], v[largest]);
            max_heapify(largest);
        }
    }

    size_t parent(size_t i) const { return (i - 1) >> 1; }

    size_t left(size_t i) const { return i << 1 + 1; }

    size_t right(size_t i) const { return i << 1 + 2; }

};

int main()
{
    //std::priority_queue<int> queue;
    priority_queue<int> p;
    for (int i = 0; i < 100; i++) {
        p.push(rand());
    }

    for (int i = 0; i < 100; i++) {
        std::cout << p.top() << " ";
        p.pop();
    }
}