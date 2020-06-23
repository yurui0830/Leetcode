//
//  main.cpp
//  81 Search in Rotated Sorted Array II
//
//  Created by 睿于 on 2020/6/23.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 81 Search in Rotated Sorted Array II / Medium / Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]). You are given a target value to search. If found in the array return true, otherwise return false.
 
    Example 1:
    Input: nums = [2,5,6,0,0,1,2], target = 0
    Output: true
 
    Example 2:
    Input: nums = [2,5,6,0,0,1,2], target = 3
    Output: false
 */

#include <iostream>
#include <vector>
using namespace::std;

bool search(vector<int>& nums, int target) {
    // empty vector, return 0
    if (nums.size() == 0)
        return false;
    // search from the beginning
    if (target > nums.back()){
        auto it = nums.begin();
        while (true){
            if (target == *it)
                return true;
            if (it >= nums.end() || *it > *(++it))
                return false;
        }
    // search from the end
    }else{  // condition: target <= nums.back()
        auto it = nums.end()-1;
        while (true){
            if (target == *it)
                return true;
            if (it <= nums.begin() || *(--it) > *it)
                return false;
        }
    }
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> nums = {2,5,6,0,0,1,2};
    bool res = search(nums, 0);
    cout << res << endl;
    res = search(nums, 3);
    cout << res << endl;
    return 0;
}
