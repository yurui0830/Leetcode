//
//  main.cpp
//  123 Best Time to Buy and Sell Stock III
//
//  Created by 睿于 on 2020/7/1.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 123 Best Time to Buy and Sell Stock III / Hard / Say you have an array for which the ith element is the price of a given stock on day i. Design an algorithm to find the maximum profit. You may complete at most two transactions. Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

    Example 1:
    Input: [3,3,5,0,0,3,1,4]
    Output: 6
    Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
                 Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
    Example 2:
    Input: [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
                 Note that you cannot buy on day 1, buy on day 2 and sell them later, as you areengaging multiple transactions at the same time. You must sell before buying again.
    Example 3:
    Input: [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

// finite-state machine
int maxProfit(vector<int>& prices) {
    // state 1: first buy, state 2: first sell, state 3: second buy, state 4: second sell
    int s1 = -prices[0]; // buy at the first day
    int s2 = INT_MIN, s3 = INT_MIN;
    int s4 = 0; // no transaction is done
    for (int i=0; i<prices.size(); i++) {
        s1 = max(s1, -prices[i]); // buy in a lower price
        s2 = max(s2, s1 + prices[i]); // do nothing or sell for the first time
        s3 = max(s3, s2 - prices[i]); // do nothing or buy for the second time
        s4 = max(s4, s3 + prices[i]); // do nothing or sell for the second time
        cout<< s1<< " " << s2 <<" " << s3 <<" "<< s4 << endl;
    }
    return s4;
}

int main(int argc, const char * argv[]) {
    vector<int> prices = {7,6,4,3,1};
    std::cout << maxProfit(prices) << endl;
    return 0;
}
