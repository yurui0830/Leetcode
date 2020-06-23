//
//  main.cpp
//  352 Data Stream as Disjoint Intervals
//
//  Created by 睿于 on 2020/6/22.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 352 Data Stream as Disjoint Intervals / Hard / Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.
 */

#include <iostream>
#include <vector>
using namespace::std;

class SummaryRanges {
public:
    SummaryRanges(vector<int> nums = {}) {
        this->numList = nums;
    }
    
    void addNum(int val) {
        // insert value
        if (numList.size() == 0){
            numList.push_back(val);
            return;
        }
        // numList is in ascending order
        auto i = numList.begin();
        auto j = numList.end();
        while(*i<val && i<j){
            i++;
        }
        // ignore exist value
        if (*i == val)
            return;
        numList.insert(i, val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        auto i=numList.begin();
        while (i<numList.end()){
            vector<int> interval = {*i}; // left element
            while (*(i+1)-*i == 1)
                i++;
            interval.push_back(*i); // right element
            i++;
            res.push_back(interval);
        }
        return res;
    }
    
    ~SummaryRanges();
    
private:
    vector<int> numList;
};

int main(int argc, const char * argv[]) {
    SummaryRanges* nums = new SummaryRanges();
    nums->addNum(1);
    nums->addNum(2);
    nums->addNum(3);
    nums->addNum(5);
    nums->addNum(7);
    nums->addNum(6);
    vector<vector<int>> res = nums->getIntervals();
    // print result
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            cout<< res[i][j] <<'\t';
        }
        cout<<'\n';
    }
    return 0;
}
