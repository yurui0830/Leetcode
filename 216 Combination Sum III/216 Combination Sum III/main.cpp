//
//  main.cpp
//  216 Combination Sum III
//
//  Created by 睿于 on 2020/7/1.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 216 Combination Sum III / Medium / Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
    Note:
    1 All numbers will be positive integers.
    2 The solution set must not contain duplicate combinations.

    Example 1:
    Input: k = 3, n = 7
    Output: [[1,2,4]]
    
    Example 2:
    Input: k = 3, n = 9
    Output: [[1,2,6], [1,3,5], [2,3,4]]
 */

#include <iostream>
#include <vector>
using namespace::std;

void combinationSum(int k, int n, vector<int>& sum3, vector<vector<int>>& combination){
    // right combination, save
    if (sum3.size() == k && n == 0){
        combination.push_back(sum3);
        return;
    }
    // recursive
    if (sum3.size() < k) {
        for (int num = sum3.empty()? 1:sum3.back()+1; num<=9; num++) {
            // wrong combination, break
            if (n - num < 0)
                break;
            // right combination, keep going
            sum3.push_back(num);
            // recursive
            combinationSum(k, n-num, sum3, combination);
            // clear last combination, try next combination
            sum3.pop_back();
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> combination;
    vector<int> sum3; // three numbers, their sum equal to n
    combinationSum(k, n, sum3, combination);
    return combination;
}

int main(int argc, const char * argv[]) {
    // test
    vector<vector<int>> res = combinationSum3(3, 10);
    // print result
    cout<< "result" <<endl;
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[0].size(); j++) {
            cout<< res[i][j] << '\t';
        }
        cout<< '\n';
    }
    return 0;
}
