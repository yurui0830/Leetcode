//
//  main.cpp
//  85 Maximal Rectangle
//
//  Created by 睿于 on 2020/6/25.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 85 Maximal Rectangle / Hard / Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

    Example:
    Input:
    [
      ["1","0","1","0","0"],
      ["1","0","1","1","1"],
      ["1","1","1","1","1"],
      ["1","0","0","1","0"]
    ]
    Output: 6
 */

#include <iostream>
#include <vector>
#include <numeric>
using namespace::std;

// Problem #84, calculate the largest area in histogram given bar heights
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

// calculate the largest rectangle area in a matrix
int maximalRectangle(vector<vector<char>>& matrix) {
    int m = int(matrix.size()), n = int(matrix[0].size()); // matrix size: m*n
    // char matrix -> integer matrix
    vector<vector<int>> hMat(m, vector<int>(n)); // height matrix
    int i, height;
    for (int j=0; j<n; j++){ // column
        i = 0;
        height = 0;
        while (i<m) {
            if (matrix[i][j] == '1'){
                hMat[i][j] = ++height;
            }else{
                height = 0;
                hMat[i][j] = 0;
            }
            i++;
        }
    }
    // row -> histogram
    int maxRectArea = 0;
    for (int i=0; i<m; i++) {
        maxRectArea = max(maxRectArea, largestRectangleArea(hMat[i]));
    }
    return maxRectArea;
}

int main(int argc, const char * argv[]) {
    // test
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}};
    std::cout << maximalRectangle(matrix)<< endl;
    return 0;
}
