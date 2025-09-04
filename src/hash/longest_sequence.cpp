#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int longestConsecutive(std::vector<int>& nums) {
    // set去重处理
    std::unordered_set<int> set(nums.begin(), nums.end());

    int maxLength = 0;
    for (int num : set) {
        // num为序列起点时才拓展，例如 nums = [100,4,200,1,3,2] num=2 
        if (set.find(num - 1) == set.end()) {
            int curNum = num;
            int curLength = 1;

            // 从num开始寻找序列，逐渐递增
            while (set.find(curNum + 1) != set.end()) {
                curLength++;
                curNum++;
            }
            maxLength = std::max(maxLength, curLength);
        }
    }
    return maxLength;
}