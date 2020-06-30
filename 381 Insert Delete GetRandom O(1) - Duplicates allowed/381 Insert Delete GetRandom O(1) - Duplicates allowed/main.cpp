//
//  main.cpp
//  381 Insert Delete GetRandom O(1) - Duplicates allowed
//
//  Created by 睿于 on 2020/6/30.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 381 Insert Delete GetRandom O(1) - Duplicates allowed / Hard / Design a data structure that supports all following operations in average O(1) time.
    Note: Duplicate elements are allowed.
    1 insert(val): Inserts an item val to the collection.
    2 remove(val): Removes an item val from the collection if present.
    3 getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
 
    Example:
    // Init an empty collection.
    RandomizedCollection collection = new RandomizedCollection();
    // Inserts 1 to the collection. Returns true as the collection did not contain 1.
    collection.insert(1);
    // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
    collection.insert(1);
    // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
    collection.insert(2);
    // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
    collection.getRandom();
    // Removes 1 from the collection, returns true. Collection now contains [1,2].
    collection.remove(1);
    // getRandom should return 1 and 2 both equally likely.
    collection.getRandom();
 */
#include <iostream>
#include <vector>
#include <map>
#include "stdlib.h"
using namespace::std;

class RandomizedCollection {
public:
    vector<int> nums; // numbers, allow duplicate
    map<int, int> count; // map: numbers, frequent
    int n; // total amount of numbers
    
    // construction function
    RandomizedCollection() {
        this->n = 0;
    }
    bool insert(int val) {
        // vector insert
        nums.push_back(val);
        // amount + 1
        n++;
        // map insert
        if (count.find(val) == count.end()){
            count[val] = 1;
            return true;
        }else{
            count[val]++;
            return false;
        }
    }
    bool remove(int val) {
        // does not exist
        if (count.find(val) == count.end()){
            return false;
        // exist, remove
        }else{
            // amount - 1
            n--;
            // map remove
            if (--count[val] == 0)
                count.erase(val);
            // vector remove
            nums.erase(find(nums.begin(), nums.end(), val));
            return true;
        }
    }
    int getRandom() {
        // random int [0,n)
        int randInt = rand() % n;
        return nums[randInt];
    }
};

int main(int argc, const char * argv[]) {
    // test
    RandomizedCollection* obj = new RandomizedCollection();
    cout<< "Insert" << endl;
    cout<< obj->insert(1) <<endl;
    cout<< obj->insert(2) <<endl;
    cout<< obj->insert(3) <<endl;
    cout<< "Remove" <<endl;
    cout<< obj->remove(1) <<endl;
    cout<< "Random" <<endl;
    cout<< obj->getRandom() <<endl;
    return 0;
}
