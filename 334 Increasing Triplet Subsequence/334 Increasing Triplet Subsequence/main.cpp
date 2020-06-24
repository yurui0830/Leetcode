//
//  main.cpp
//  334 Increasing Triplet Subsequence
//
//  Created by 睿于 on 2020/6/24.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 334 Increasing Triplet Subsequence / Medium / Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array. Formally the function should: Return true if there exists i, j, k such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false. Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

    Example 1:
    Input: [1,2,3,4,5]
    Output: true
     
    Example 2:
    Input: [5,4,3,2,1]
    Output: false
 */

#include <iostream>
#include <vector>
using namespace::std;

bool increasingTriplet(vector<int>& nums) {
    int min1 = INT_MAX, min2 = INT_MAX; // min1: smallest, min2: second smallest
    for (auto it=nums.begin(); it<nums.end(); it++){
        if (*it <= min1) // the smallest value so far
            min1 = *it;
        else if (*it <= min2) // the second smallest value so far
            min2 = *it;
        else
            return true; // larger than the second smallest number
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> nums = {1,2,4,2,5,7,4,2,3};
    cout << increasingTriplet(nums) <<endl;
    return 0;
}
