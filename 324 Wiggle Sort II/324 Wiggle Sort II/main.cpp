//
//  main.cpp
//  324 Wiggle Sort II
//
//  Created by 睿于 on 2020/6/23.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 324 Wiggle Sort II / Medium / Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3].... Note: You may assume all input has valid answer.

    Example 1:
    Input: nums = [1, 5, 1, 1, 6, 4]
    Output: One possible answer is [1, 4, 1, 5, 1, 6].
     
    Example 2:
    Input: nums = [1, 3, 2, 2, 3, 1]
    Output: One possible answer is [2, 3, 1, 3, 1, 2].
 */

#include <iostream>
#include <vector>
using namespace::std;

void swap (int& a, int& b) {
  int t = a;
  a = b;
  b = t;
}

// Solution I, complexity O(n log(n))
void wiggleSort(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // sorting in ascending order
    auto it1 = nums.begin()+1; // small values
    auto it2 = nums.size()%2==0? nums.end()-2:nums.end()-1; // large values
    auto smallest = nums.begin();
    auto largest = nums.size()%2==0? nums.end()-1:nums.end()-2;;
    while (it1 < it2){
        if (*it1 == *it2){
            swap(*it1, *smallest); // swap the small value and the smallest one
            smallest -= 2;
            swap(*it2, *largest); // swap the large value and the largest one
            largest += 2;
        }
        swap(*it1, *it2); // swap
        it1 += 2;
        it2 -= 2;
    }
}

// Solution II, complexity O(n)
void wiggleSort_2(vector<int>& nums) {
    auto it1 = nums.begin(); // small values
    auto it2 = nums.begin()+1; // large values
    auto smallest = nums.begin(); // smallest value of the vector
    vector<int>::iterator itMin;
    vector<int>::iterator itMax;
    while (it1 < nums.end() && it2 < nums.end()){
        itMin = min_element(it1, nums.end());
        itMax = max_element(it1, nums.end());
        if (*itMin == *itMax) {
            swap(*it1, *smallest);
            swap(*it2, *(it2-2));
            smallest += 2;
        }else {
            swap(*it1, *itMin);
            swap(*it2, *itMax);
        }
        it1 += 2;
        it2 += 2;
    }
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> nums = {1, 3, 2, 2, 3, 1, 2}, nums_2 = {1, 3, 2, 2, 3, 1, 2};
    wiggleSort(nums);
    wiggleSort_2(nums_2);
    // print results
    for (int i=0; i<nums.size(); i++) {
        cout<< nums[i] <<'\t';
    }
    cout<<endl;
    for (int i=0; i<nums.size(); i++) {
        cout<< nums_2[i] <<'\t';
    }
    cout<<endl;
    return 0;
}
