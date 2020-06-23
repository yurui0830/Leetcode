//
//  main.cpp
//  295 Find Median from Data Stream
//
//  Created by 睿于 on 2020/6/23.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 295 Find Median from Data Stream / Hard / Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

     For example,
     [2,3,4], the median is 3
     [2,3], the median is (2 + 3) / 2 = 2.5

     Design a data structure that supports the following two operations:
         1 void addNum(int num) - Add a integer number from the data stream to the data structure.
         2 double findMedian() - Return the median of all elements so far.
 
     Example:
         addNum(1)
         addNum(2)
         findMedian() -> 1.5
         addNum(3)
         findMedian() -> 2
 */

#include <iostream>
#include <vector>
#include <numeric>
using namespace::std;

class MedianFinder {
public:
    MedianFinder(vector<int> nums={}) {
        this->nums = nums;
    }
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return double(sum)/nums.size();
    }
private:
    vector<int> nums;
};

int main(int argc, const char * argv[]) {
    // test
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    double med = obj->findMedian();
    cout << med <<'\n';
    obj->addNum(8);
    med = obj->findMedian();
    cout << med<<'\n';
    return 0;
}
