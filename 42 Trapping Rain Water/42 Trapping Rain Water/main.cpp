//
//  main.cpp
//  42 Trapping Rain Water
//
//  Created by 睿于 on 2020/6/24.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 42 Trapping Rain Water / Hard / Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
    ^
    |
    |                __
    |      __        ____  __
    |  __  __  __  ____________
    |_____________________________>
    Example:
    Input: [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
 */

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace::std;

int trap(vector<int>& height){
    if (height.size() < 3)
        return 0;
    int trapUnit = 0; // return value
    // search for the saddle in the middle
    auto Max = max_element(height.begin(), height.end()); // maximum value
    int temp = *Max;
    *Max = -1;
    auto Max_2nd = max_element(height.begin(), height.end()); // second maximum value
    *Max = temp;
    auto lMax = min(Max, Max_2nd);
    auto rMax = max(Max, Max_2nd);
    // calculate the amount of trapped units
    int barHeight = min(*lMax, *rMax); // the height of the shortest bar
    for (auto i=lMax+1; i<rMax; i++)
        trapUnit += (barHeight-*i)>0? (barHeight-*i):0;
    // {left bar| saddle | right bar}, recursive
    vector<int> lBars = {height.begin(), lMax+1};
    vector<int> rBars = {rMax, height.end()};
    trapUnit += trap(lBars);
    trapUnit += trap(rBars);
    return trapUnit;
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> height = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};
    cout << trap(height) <<endl;
    return 0;
}
