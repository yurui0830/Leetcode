//
//  main.cpp
//  239	Sliding Window Maximum
//
//  Created by 睿于 on 2020/6/23.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 239 Sliding Window Maximum / Hard / Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
 
     Example:
     Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
     Output: [3,3,5,5,6,7]
     
     Explanation:
     Window position                Max
     ---------------               -----
     [1  3  -1] -3  5  3  6  7       3
      1 [3  -1  -3] 5  3  6  7       3
      1  3 [-1  -3  5] 3  6  7       5
      1  3  -1 [-3  5  3] 6  7       5
      1  3  -1  -3 [5  3  6] 7       6
      1  3  -1  -3  5 [3  6  7]      7
 */

#include <iostream>
#include <vector>
using namespace::std;

// find the maximum value from given numbers
int maxElement(vector<int>& nums){
    auto it = max_element(nums.begin(), nums.end());
    return *it;
}

// sliding window
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> slideMax;
    auto it = nums.begin();
    while (it+k <= nums.end()){
        vector<int> slideWin = {it, it+k};
        slideMax.push_back(maxElement(slideWin)); // call maxElement function
        it++;
    }
    return slideMax;
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);
    // print results
    for (int i=0; i<res.size(); i++) {
        cout<< res[i] <<'\t';
    }
    cout << endl;
    return 0;
}
