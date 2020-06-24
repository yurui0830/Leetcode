//
//  main.cpp
//  347 Top K Frequent Elements
//
//  Created by 睿于 on 2020/6/24.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 347 Top K Frequent Elements / Medium/ Given a non-empty array of integers, return the k most frequent elements.
     Note:
     1 You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
     2 Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
     3 It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
     4 You can return the answer in any order.

    Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
     
    Example 2:
    Input: nums = [1], k = 1
    Output: [1]
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace::std;
typedef pair<int,int> freqNum;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // numFreq: {numbers, frequency}
    map<int, int> numFreq;
    for (auto it=nums.begin(); it<nums.end(); it++)
        numFreq[*it]++;
    // prioirity queque: ascending order by the first argument(frequency)
    priority_queue<pair<int,int>> q;
    for (auto it=numFreq.begin(); it!=numFreq.end(); it++)
        q.push(make_pair(it->second, it->first));
    // top K frequent numbers
    vector<int> kFreq;
    for (int i=0; i<k; i++) {
        kFreq.push_back(q.top().second);
        q.pop();
    }
    return kFreq;
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> nums = {1,1,1,2,2,3,4,4,4,4,4,5,5,5,5,5,5,6};
    vector<int> res = topKFrequent(nums, 4);
    // print results
    for (int i=0; i<res.size(); i++) {
        cout<< res[i] <<'\t';
    }
    cout << endl;
    return 0;
}
