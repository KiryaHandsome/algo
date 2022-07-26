#include <vector>
#include <stdexcept>
#include <iostream>
#include <queue>

template<class T, class Container = std::vector<T>>
class priority_queue
{
    using const_reference = const T&;
private:
    Container v;
public:
    priority_queue() { }

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
        emplace(value);
    }

    template<class ...Args>
    void emplace(Args&&... args)
    {
        v.emplace_back(std::forward<Args>(args)...);
        size_t i = v.size() - 1;
        size_t par = parent(i);
        while (i > 0 && v[i] > v[par]) {
            std::swap(v[i], v[par]);
            i = par;
            par = parent(i);
        }
    }

    size_t size() const { return v.size(); }

    bool empty() const noexcept { return v.size() == 0; }

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

    size_t left(size_t i) const { return (i << 1) + 1; }

    size_t right(size_t i) const { return (i << 1) + 2; }

};
