//
//  main.cpp
//  31 Next Permutation
//
//  Created by 睿于 on 2020/6/30.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 31 Next Permutation / Medium / Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order). The replacement must be in-place and use only constant extra memory.

    Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1
 */

#include <iostream>
#include <vector>
using namespace::std;

void nextPermutation(vector<int>& nums) {
    int i = int(nums.size())-1;
    // search for the number which is lower than the number after it
    while (i>0) {
        if (nums[i-1] < nums[i])
            break;
        i--;
    }
    // if all the numbers are in decending order, sort it in ascending order
    if (i == 0){
        sort(nums.begin(), nums.end());
    // swap the numbers, and sort the following numbers
    }else{
        swap(nums[i], nums[i-1]);
        sort(nums.begin()+i, nums.end());
    }
    return;
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> nums={3,3,5,3,6,2,7,2,1};
    nextPermutation(nums);
    // print result
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] <<'\t';
    }
    cout<< endl;
    return 0;
}
