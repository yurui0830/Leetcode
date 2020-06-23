//
//  main.cpp
//  18 4Sum
//
//  Created by 睿于 on 2020/6/22.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 18 4Sum / Hard / Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 */

#include <iostream>
#include <vector>
using namespace::std;

vector<vector<int>> twoSum(vector<int> nums, int target){
    vector<vector<int>> res;
    auto c = nums.end()-1;
    auto d = nums.begin();
    while (d < c){
        if (*c+*d > target)
            c--;
        else if (*c+*d < target)
            d++;
        else if(*c+*d == target){
            res.push_back({*d, *c});
            // eliminate repeat numbers
            auto last = c;
            while (*(--c) == *last);
        }
    }
    return res;
}

vector<vector<int>> threeSum(vector<int> nums, int target){
    vector<vector<int>> res;
    while (nums.size() >= 3){
        int b = nums.back();
        nums.pop_back();
        auto twoValues = twoSum(nums, target-b);
        for (int i=0; i<twoValues.size(); i++){
            twoValues[i].push_back(b);
            res.push_back(twoValues[i]);
        }
        // eliminate repeat numbers
        while (nums.back() == b)
            nums.pop_back();
    }
    return res;
}

vector<vector<int>> fourSum(vector<int> nums, int target){
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    while (nums.size() >= 4){
        int a = nums.back();
        nums.pop_back();
        auto threeValues = threeSum(nums, target-a);
        for (int i=0; i<threeValues.size(); i++){
            threeValues[i].push_back(a);
            res.push_back(threeValues[i]);
        }
        // eliminate repeat numbers
        while (nums.back() == a)
            nums.pop_back();
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 0, -1, 0, -2, 2, 2, 1, 2};
    int target = 0;
    auto res = fourSum(nums, target);
    for (int i=0; i<res.size(); i++){
        for (int j=0; j<res[i].size(); j++){
            cout<< res[i][j] << '\t';
        }
        cout<< '\n';
    }
    return 0;
}
