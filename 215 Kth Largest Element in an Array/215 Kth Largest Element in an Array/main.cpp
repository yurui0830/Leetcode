//
//  main.cpp
//  215 Kth Largest Element in an Array
//
//  Created by 睿于 on 2020/6/24.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 215 Kth Largest Element in an Array / Medium/ Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element. Note: You may assume k is always valid, 1 ≤ k ≤ array's length.

    Example 1:
    Input: [3,2,1,5,6,4] and k = 2
    Output: 5
     
    Example 2:
    Input: [3,2,3,1,2,4,5,5,6] and k = 4
    Output: 4
 */

#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace::std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int> > q; // a queue in decending order;
    for (auto it=nums.begin(); it<nums.end(); it++){
        q.push(*it);
        // only keep k largest numbers in the queue
        if (q.size() > k)
            q.pop();
    }
    return q.top(); // the k-th largest number
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> nums = {3,2,1,5,6,4};
    cout << findKthLargest(nums, 2) <<endl;
    return 0;
}
