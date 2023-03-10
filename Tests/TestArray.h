#ifndef _T_TESTARRAY_H_
#define _T_TESTARRAY_H_

#include <iostream>
#include <assert.h>
#include "../DS/Arrays/StaticArray.h"
#include "../DS/Arrays/DynamicArray.h"
#include "./BlockTimer.h"

class StaticArrayTest {

private:

public:
    StaticArrayTest(std::string name) {
        for(int X = 0; ;X++) {
            StaticArray<int, 10000> array(0);
            for(int i = 0 ; i < 10000; i++) {
                array.push(rand());
            }
            std::cout << "\033[1;32m" << name << ": Test 1: adding 10000 random elements and sorting:";
            auto cmp = [](const int& a, const int& b) -> bool {
                return a >= b;
            };
            try {
                int val;
                {
                    BlockTimer timer("\nFinding Max");
                    auto max = array.max();
                    std::cout << "\nMax: " << max.first << " Index: " << max.second;
                }
                {
                    BlockTimer timer("\nFinding Min");
                    auto min = array.min();
                    std::cout << "\nMin: " << min.first << " Index: " << min.second;
                }
                {
                    val = array[9999];
                    BlockTimer timer("\nLinear Searching");
                    int idx = array.search(val);
                }
                {
                    BlockTimer timer("\nSorting");
                    array.sort(32, cmp);
                }
                { 
                    BlockTimer timer("\nBinary Searching");
                    int idx = array.binarySearch(val, cmp);
                    if(val != array[idx]) throw 200;
                }
                std::cout << "\nFirst 10 elements: ";
                array.resize(10);
                for(int i = 0; i < array.getSize(); i++) {
                    std::cout << array[i] << " ";
                }
                std::cout << "\nTest " << X + 1 << " passed\033[0m\n";
            } catch (...) {
                std::cout << "\033[1;31mTest failed \033[0m\n";
                break;
            }
        }
    }
};


#endif