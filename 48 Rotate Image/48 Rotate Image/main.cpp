//
//  main.cpp
//  48 Rotate Image
//
//  Created by 睿于 on 2020/6/23.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 48 Rotate Image / Medium / You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise). Note: You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 
     Example:
     Given input matrix =
     [
       [ 5, 1, 9,11],
       [ 2, 4, 8,10],
       [13, 3, 6, 7],
       [15,14,12,16]
     ],
     rotate the input matrix in-place such that it becomes:
     [
       [15,13, 2, 5],
       [14, 3, 4, 1],
       [12, 6, 8, 9],
       [16, 7,10,11]
     ]
 */

#include <iostream>
#include <vector>
using namespace::std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size(); // matrix size: n*n
    int i = 0; // row
    int j = 0; // column
    // rotate
    while (i<= n/2){
        int temp = matrix[i][j];
        matrix[i][j] = matrix[n-j-1][i];
        matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
        matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
        matrix[j][n-i-1] = temp;
        if (j >= n-i-2){
            i++;
            j = i;
        }else{
            j++;
        }
    }
}

int main(int argc, const char * argv[]) {
    // test
    vector<vector<int>> matrix ={
        {11,12,13,14,15,16},
        {21,22,23,24,25,26},
        {31,32,33,34,35,36},
        {41,42,43,44,45,46},
        {51,52,53,54,55,56},
        {61,62,63,64,65,66}
    };
    rotate(matrix);
    // print results
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[i].size(); j++){
            cout<< matrix[i][j] << '\t';
        }
        cout<< '\n';
    }
    return 0;
}
