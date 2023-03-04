#include <iostream>
#include <assert.h>
#include "../DS/Arrays/StaticArray.h"
#include "./BlockTimer.h"

class StaticArrayTest {

private:

public:
    StaticArrayTest(std::string name) {
        StaticArray<int, 100000> array;
        for(int i = 0 ; i < array.getSize(); i++) {
            array[i] = rand();
        }
        std::cout << "\033[1;32m" << name << ": Test 1: adding 100000 random elements and sorting:";
        try {
            int val;
            {
                BlockTimer timer("\nFinding Max");
                auto max = array.max();
                // std::cout << "\nMax: " << max.first << " Index: " << max.second;
            }
            {
                BlockTimer timer("\nFinding Min");
                auto min = array.min();
                // std::cout << "\nMin: " << min.first << " Index: " << min.second;
            }
            {
                val = array[99999];
                BlockTimer timer("\nLinear Searching");
                int idx = array.search(val);
            }
            {
                BlockTimer timer("\nSorting");
                array.sort(64);
            }
            { 
                BlockTimer timer("\nBinary Searching");
                int idx = array.binarySearch(val);
            }
            for(int i = 1; i < array.getSize(); i++) {
                if (array[i] < array[i - 1]) throw 100;
            }
            std::cout << "\nTest 1 passed\033[0m\n";
        } catch (...) {
            std::cout << "\033[1;31mTest failed \033[0m\n";
        }
    }
};

int main() {
    StaticArrayTest("Static Array");
    return 0;
}