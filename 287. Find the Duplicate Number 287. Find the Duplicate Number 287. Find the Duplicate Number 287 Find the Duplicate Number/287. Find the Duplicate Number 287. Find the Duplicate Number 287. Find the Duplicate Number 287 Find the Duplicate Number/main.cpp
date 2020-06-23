//
//  main.cpp
//  287. Find the Duplicate Number 287. Find the Duplicate Number 287. Find the Duplicate Number 287 Find the Duplicate Number
//
//  Created by 睿于 on 2020/6/23.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 287 Find the Duplicate Number / Medium / Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
    Note:
     1 You must not modify the array (assume the array is read only).
     2 You must use only constant, O(1) extra space.
     3 Your runtime complexity should be less than O(n2).
     4 There is only one duplicate number in the array, but it could be repeated more than once.
     
    Example 1:
    Input: [1,3,4,2,2]
    Output: 2
     
    Example 2:
    Input: [3,1,3,4,2]
    Output: 3
 */

#include <iostream>
#include <vector>
using namespace::std;

int findDuplicate(vector<int>& nums) {
    auto it = nums.begin();
    while (it < nums.end()){
        // the value is negtive, which means the index is repeated
        if (nums[abs(*it)] < 0)
            return abs(*it);
        // turn into a negtive value
        nums[abs(*it)] = -nums[abs(*it)];
        it++;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> nums = {1,3,4,3,2};
    cout << findDuplicate(nums) <<endl;
    return 0;
}
