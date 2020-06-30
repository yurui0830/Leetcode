//
//  main.cpp
//  219 Contains Duplicate II
//
//  Created by 睿于 on 2020/6/30.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 219 Contains Duplicate II / Easy / Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

    Example 1:
    Input: nums = [1,2,3,1], k = 3
    Output: true
     
    Example 2:
    Input: nums = [1,0,1,1], k = 1
    Output: true
     
    Example 3:
    Input: nums = [1,2,3,1,2,3], k = 2
    Output: false
 */

#include <iostream>
#include <vector>
#include <map>
using namespace::std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    // map: number, index
    map<int, int> count;
    for(int i=0; i<nums.size(); i++){
        auto it = count.find(nums[i]);
        // if this number is alreday in the map, check the index
        if(it != count.end()){
            if(i - it->second <= k)
                return true;
            else
                it->second = i;
        // if this number is not in the map, add it
        }else
            count.insert(pair<int, int>(nums[i], i));
    }
    return false;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3,1,2,3};
    cout << containsNearbyDuplicate(nums, 2) <<endl;
    return 0;
}
