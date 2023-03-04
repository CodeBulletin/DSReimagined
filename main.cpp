#include <iostream>
#include "DS/Arrays/StaticArray.h"

int main() {
    StaticArray<int, 100> array;
    for(int i = 0; i < array.getSize(); i++) {
        array.set(i, 96 - i);
    }
    auto cmp = [](const int& a, const int& b) -> bool {
        return a >= b;
    };
    array.sort(32, cmp);

    for(int i = 0; i < array.getSize(); i++) {
        std::cout << array.get(i) << " ";
    }
    std::cout << "\nMin: " << array.min().first;
    std::cout << "\nMax: " << array.max().first;
    std::cout << "\nIndex of 50: " << array.search(50) << " | value: " << array[array.search(50)];
    std::cout << "\nIndex of 50: " << array.binarySearch(50, cmp) << " | value: " << array[array.binarySearch(50, cmp)] << std::endl;
    return 0;
}