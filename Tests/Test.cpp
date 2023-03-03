#include <iostream>
#include <assert.h>

class basicTest {

private:

public:
    basicTest(std::string name) {
        int x = 3;
        std::cout << "\033[1;32m" << name << ": Test 1: ";
        if (x == 2)
            std::cout << "passed\033[0m\n";
        else {
            std::cout << "\033[1;31mTest failed \033[0m\n";
            assert(x == 2);
        }
    }
};

int main() {
    basicTest("A");
    basicTest("B");
    basicTest("C");
    basicTest("D");
    return 0;
}