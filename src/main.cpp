#include <iostream>
#include "test.h"
#include "longest_sequence.cpp"

int main() {

    std::cout << "This is my cpp learning demo" << std::endl;
    
    std::vector<int> nums = { 100, 4, 200, 1, 3, 2 };

    int maxLength = longestConsecutive(nums);

    std::cout << "max Length: " << maxLength << std::endl;

    printTest();

    return 0;
}