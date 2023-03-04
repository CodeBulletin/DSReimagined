#ifndef _T_BLOCKTIMER_H_;
#define _T_BLOCKTIMER_H_;

#include <iostream>
#include <chrono>

class BlockTimer {
private:
    std::string name;
    std::chrono::_V2::system_clock::time_point t1;
public:
    BlockTimer(std::string name) : name(name) {
        t1 = std::chrono::high_resolution_clock::now();
    }
    ~BlockTimer() {
        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << name << " took " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
    }
};


#endif