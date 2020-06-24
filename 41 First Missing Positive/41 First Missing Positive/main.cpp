//
//  main.cpp
//  41 First Missing Positive
//
//  Created by 睿于 on 2020/6/24.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 41 First Missing Positive / Hard / Given an unsorted integer array, find the smallest missing positive integer. Note: Your algorithm should run in O(n) time and uses constant extra space.

    Example 1:
    Input: [1,2,0]
    Output: 3
     
    Example 2:
    Input: [3,4,-1,1]
    Output: 2
     
    Example 3:
    Input: [7,8,9,11,12]
    Output: 1
 */

#include <iostream>
#include <vector>
#include <map>
using namespace::std;

int firstMissingPositive(vector<int>& nums) {
    // map numList: {number, true/false}
    map<int, bool> numList;
    // label the existing number as true
    for (auto it=nums.begin(); it<nums.end(); it++) {
        numList[*it] = true;
    }
    // search for the first number without a true flag
    int i = 1;
    while (i<=nums.size()){
        if (!numList[i])
            return i;
        i++;
    }
    return i;
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> nums = {1,2,3,4,5,6};
    cout<< firstMissingPositive(nums)<< endl;
    return 0;
}
