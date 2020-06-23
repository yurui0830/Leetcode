//
//  main.cpp
//  57 Insert Interval
//
//  Created by 睿于 on 2020/6/22.
//  Copyright © 2020 睿于. All rights reserved.
//
/*
 57 Insert Interval / Hard / Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary). You may assume that the intervals were initially sorted according to their start times.
 
 Example 1:
 Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 Output: [[1,5],[6,9]]
 
 Example 2:
 Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 Output: [[1,2],[3,10],[12,16]]
 Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 */

#include <iostream>
#include <vector>
using namespace::std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> newInterval) {
    int left = newInterval[0];
    int right = newInterval[1];
    auto i = intervals.begin();
    auto j = intervals.end()-1;
    while (i <= j){
        if ((*i)[1] < left)
            i++;
        else if ((*j)[0] > right)
            j--;
        else
            break;
    }
    // add a new interval
    if (i == j+1){
        intervals.insert(i, newInterval);
        return intervals;
    }
    // set the minimum value as the left value
    (*i)[0] = (*i)[0]>left? left:(*i)[0];
    // set the maximum value as the right value
    (*i)[1] = (*j)[1]<right? right:(*j)[1];
    // merge the intervals which will be covered by the new itv
    intervals.erase(i+1, j+1);
    return intervals;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> intervals = {{1,3},{4,5},{8,9},{10,11}};
    vector<int> newInterval = {9,10};
    vector<vector<int>> res = insert(intervals, newInterval);
    // print result
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            cout<< res[i][j] << '\t';
        }
        cout<< '\n';
    }
    return 0;
}
