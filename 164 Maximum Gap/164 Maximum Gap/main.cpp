//
//  main.cpp
//  164 Maximum Gap
//
//  Created by 睿于 on 2020/6/23.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 164 Maximum Gap / Hard / Given an unsorted array, find the maximum difference between the successive elements in its sorted form. Return 0 if the array contains less than 2 elements. Note: You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range. Try to solve it in linear time/space.
 
    Example 1:
    Input: [3,6,9,1]
    Output: 3
    Explanation: The sorted form of the array is [1,3,6,9], either
                  (3,6) or (6,9) has the maximum difference 3.
     
    Example 2:
    Input: [10]
    Output: 0
    Explanation: The array contains less than 2 elements, therefore return 0.
 */

#include <iostream>
#include <vector>
using namespace::std;

int maximumGap(vector<int>& nums) {
    if (nums.size() < 2)
        return 0;
    int maxGap = 0;
    auto max = max_element(nums.begin(), nums.end()); // minimum value
    auto min = min_element(nums.begin(), nums.end()); // maximum value
    int range = *max - *min; // value range
    int step = range/(nums.size()-1)>1? range/(nums.size()-1):1;
    int groupN = range/step + 1; // devided range into {groupN} bins according to the distance
    vector<int> groupMax(groupN, INT_MIN); // maximum value of each bin
    vector<int> groupMin(groupN, INT_MAX); // minimum value of each bin
    int distance = 0; // distance between the value and the minimum value
    // put values into corresponding bin
    for (auto it=nums.begin(); it<nums.end(); it++){
        distance = (*it-*min)/step;
        groupMax[distance] = groupMax[distance]>*it? groupMax[distance]:*it;
        groupMin[distance] = groupMin[distance]<*it? groupMin[distance]:*it;
    }
    // find the maximum gap
    for (int i=0; i<groupN; i++){
        if (groupMax[i] == INT_MAX)
            continue;
        for (int j=i+1; j<groupN; j++){
            if (groupMin[j] == INT_MAX)
                continue;
            maxGap = (groupMin[j]-groupMax[i])>maxGap? (groupMin[j]-groupMax[i]):maxGap;
            break;
        }
    }
    return maxGap;
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> nums = {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
    cout << maximumGap(nums) <<endl;
    return 0;
}
