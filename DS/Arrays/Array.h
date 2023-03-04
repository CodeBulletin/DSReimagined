#ifndef _DS_ARRAY_H_
#define _DS_ARRAY_H_

#include "../Container.h"
#include <stdexcept>
#include <functional>
// #include <format>

template<class T>
class Array : public Container<T> {
private:
    void _insertionSort(T *arr, size_t l, size_t r, std::function<bool(T, T)> cmp) {
        for(size_t i = l+1; i <= r; i++) {
            T temp = arr[i];
            long j = i - 1;
            while (j >= (long)l && !cmp(arr[j], temp)) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
    }

    void _merge(T *arr, size_t l, size_t m, size_t e, std::function<bool(T, T)> cmp) {
        size_t l2 = m + 1;
        if (arr[m] <= arr[l2]) return;
        while (l <= m && l2 <= e) {
            if(cmp(arr[l], arr[l2])) {
                l++;
                continue;
            }
            T value = arr[l2];
            size_t idx = l2;
            while (idx != l) {
                arr[idx] = arr[idx - 1];
                idx--;
            }
            arr[l] = value;
            l++;
            l2++;
            m++;
        }
        
    }

    static bool accending(const T& a, const T& b) {
        return a <= b;
    }

protected:
    T* m_array;

public:
    virtual T& get(size_t idx) {
        if (idx < 0 || idx >= this->m_size) throw std::out_of_range("Index out of range");
        return m_array[idx];
    }
    virtual bool set(size_t idx, T val) {
        if (idx < 0 || idx >= this->m_size) throw std::out_of_range("Index out of range");
        m_array[idx] = val;
        return true;
    }
    virtual void sort(size_t run = 32, std::function<bool(T, T)> cmp = accending) {
        for(size_t i = 0; i < this->m_size; i+=run) {
            _insertionSort(this->m_array, i, std::min(i + run - 1, this->m_size - 1), cmp);
        }
        for(size_t size = run; size < this->m_size; size = 2 * size) {
            for (size_t left = 0; left < this->m_size; left += 2 * size) {
                size_t mid = left + size - 1;
                size_t right = std::min(left + 2 * size - 1, this->m_size - 1);
                if (mid < right)
                    _merge(this->m_array, left, mid, right, cmp);
            }
        }
    }
    virtual std::pair<T, size_t> max() {
        T max = m_array[0];
        size_t idx = 0;
        for(size_t i = 1; i < this->m_size; i++) {
            if (max < this->m_array[i]) {
                max = this->m_array[i];
                idx = i;
            }
        }
        return {max, idx};
    }
    virtual std::pair<T, size_t> min() {
        T min = m_array[0];
        size_t idx = 0;
        for(size_t i = 1; i < this->m_size; i++) {
            if (min > this->m_array[i]) {
                min = this->m_array[i];
                idx = i;
            }
        }
        return {min, idx};
    }
    size_t search(T obj) {
        for(size_t i = 0; i < this->m_size; i++) {
            if (obj == this->m_array[i]) return i;
        }
        return this->m_size;
    }

    size_t binarySearch(T obj, std::function<bool(T, T)> cmp = accending) {
        for(int low = 0, high = this->m_size; low < high;) {
            int mid = (low + high)/2;
            if (obj == this->m_array[mid]) return mid;
            else if (!cmp(obj, this->m_array[mid])) low = mid + 1;
            else high = mid -1;
        }
        return this->m_size;
    }

    T& operator [](size_t idx) {
        if (idx < 0 || idx >= this->m_size) throw std::out_of_range("Index out of range");
        return this->m_array[idx];
    }
};

#endif