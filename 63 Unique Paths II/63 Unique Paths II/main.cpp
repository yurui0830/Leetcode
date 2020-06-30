//
//  main.cpp
//  63 Unique Paths II
//
//  Created by 睿于 on 2020/6/30.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 63 Unique Paths II / Medium / A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below). The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below). Now consider if some obstacles are added to the grids. How many unique paths would there be? An obstacle and empty space is marked as 1 and 0 respectively in the grid. Note: m and n will be at most 100.

    Example 1:
    Input:
    [
      [0,0,0],
      [0,1,0],
      [0,0,0]
    ]
    Output: 2
    Explanation:
    There is one obstacle in the middle of the 3x3 grid above.
    There are two ways to reach the bottom-right corner:
    1. Right -> Right -> Down -> Down
    2. Down -> Down -> Right -> Right
 */

#include <iostream>
#include <vector>
using namespace::std;

// dynamic progamming
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    // grid size: m*n
    int m = int(obstacleGrid.size());
    int n = int(obstacleGrid[0].size());
    // right edge and bottom edge
    obstacleGrid[m-1][n-1] = obstacleGrid[m-1][n-1]==1? 0:1; // right-bottom point
    for (int j=n-2; j>=0; j--) // bottom edge
        obstacleGrid[m-1][j] = obstacleGrid[m-1][j]==1? 0:obstacleGrid[m-1][j+1];
    for (int i=m-2; i>=0; i--) // right edge
        obstacleGrid[i][n-1] = obstacleGrid[i][n-1]==1? 0:obstacleGrid[i+1][n-1];
    // other grids
    for (int i=m-2; i>=0; i--) {
        for (int j=n-2; j>=0; j--) {
            obstacleGrid[i][j] = obstacleGrid[i][j]==1? 0:obstacleGrid[i+1][j]+obstacleGrid[i][j+1];
        }
    }
    return obstacleGrid[0][0];
}

int main(int argc, const char * argv[]) {
    // test
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(obstacleGrid) <<endl;
    return 0;
}
