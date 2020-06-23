//
//  main.cpp
//  128 Longest Consecutive Sequence
//
//  Created by 睿于 on 2020/6/23.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 128 Longest Consecutive Sequence / Hard / Given an unsorted array of integers, find the length of the longest consecutive elements sequence. Your algorithm should run in O(n) complexity.
 
    Example:
    Input: [100, 4, 200, 1, 3, 2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 */

#include <iostream>
#include <vector>
using namespace::std;

int countConsecutive(vector<int>& nums, int num) {
    int after = num+1; // numbers after the chosen number
    int before = num-1; // numbers before the chosen number
    int count = 1; // count the length of the consecutive sequence
    // find the sequence, then delete the numbers from the vector
    while(true){
        auto it = find(nums.begin(), nums.end(), after);
        if (it == nums.end()){
            while(true){
                auto it_before = find(nums.begin(), nums.end(), before);
                if (it_before == nums.end())
                    break;
                else{
                    nums.erase(it_before);
                    before--;
                    count++;
                }
            }
            break;
        }else{
            nums.erase(it);
            after++;
            count++;
        }
    }
    return count;
}

int longestConsecutive(vector<int>& nums) {
    // compare the length of each sequence
    int longest = 0; // length of the longest sequence
    while(nums.size()>1){
        int num = nums.back();
        nums.pop_back();
        int current = countConsecutive(nums, num);
        longest = longest<current? current:longest;
    }
    return longest;
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> nums = {100, 4, 200, 1, 3, 2, 101, 102, 99, 98};
    cout << longestConsecutive(nums) <<endl;
    return 0;
}
