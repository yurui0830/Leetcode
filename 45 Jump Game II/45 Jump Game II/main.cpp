//
//  main.cpp
//  45 Jump Game II
//
//  Created by 睿于 on 2020/7/1.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 45 Jump Game II / Hard / Given an array of non-negative integers, you are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Your goal is to reach the last index in the minimum number of jumps.

    Example:
    Input: [2,3,1,1,4]
    Output: 2
    Explanation: The minimum number of jumps to reach the last index is 2.
        Jump 1 step from index 0 to 1, then 3 steps to the last index.
 */

#include <iostream>
#include <vector>
using namespace::std;

int jump(vector<int>& nums) {
    int jump = 1; // count the jump
    auto it = nums.begin();
    while (it < nums.end()-1) {
        int max = *it;
        // jump over the final point
        if (it+*it >= nums.end()-1)
            return jump;
        // find next jump point
        auto maxIt = max_element(it+1, it+max+1); // the maximum value of this jump range
        auto nextmaxIt = maxIt + *maxIt; // next jump range
        auto nextIt = maxIt; // next jump point
        while (++maxIt < it+max+1){
            if (maxIt+*maxIt > nextmaxIt){
                nextmaxIt = maxIt+*maxIt;
                nextIt = maxIt;
            }
        }
        it = nextIt;
        jump++;
    }
    return jump;
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> nums = {2,3,1,1,4,3,2,6,2,7,1};
    cout << jump(nums) <<endl;
    return 0;
}
