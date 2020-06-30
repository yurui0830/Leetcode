//
//  main.cpp
//  84 Largest Rectangle in Histogram
//
//  Created by 睿于 on 2020/6/25.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 84 Largest Rectangle in Histogram / Hard / Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
    
    Example:
     ^
     |
     |      __
     |    ____
     |    ____
     |    ____  __
     |__  ________
     |____________
     |____________________>
     Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3]. The largest rectangle is shown in the shaded area, which has area = 10 unit.
    Input: [2,1,5,6,2,3]
    Output: 10
 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace::std;

int largestRectangleArea(vector<int>& heights) {
    int areaMax = 0; // return value
    int n = int(heights.size()); // amount of bars
    int left[n]; // left edge index
    int right[n]; // right edge index
    // initial edge index
    for (int i=0; i<n; i++){
        left[i] = i-1;
        right[i] = i+1;
    }
    // search for the lower value (left/right edge)
    for (int i=0; i<n; i++) {
        int l=i-1, r=i+1;
        while (l >= -1) {
            if (heights[l] < heights[i]){
                left[i] = l;
                break;
            }else if (l <= 0){
                left[i] = -1;
                break;
            }else
                l = left[l];
        }
        while (r <= n) {
            if (heights[r] < heights[i]){
                right[i] = r;
                break;
            }else if (r >= n-1){
                right[i] = n;
                break;
            }else
                r = right[r];
        }
    }
    // calculate area
    for (int i=0; i<n; i++){
        areaMax = max(areaMax, heights[i]*(right[i]-left[i]-1));
    }
    return areaMax;
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> heights = {1,1,1,1,1,1,1,1};
    cout << largestRectangleArea(heights) << endl;;
    return 0;
}
