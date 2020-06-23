//
//  main.cpp
//  test
//
//  Created by 睿于 on 2020/6/19.
//  Copyright © 2020 睿于. All rights reserved.
//

#include <iostream>
using namespace::std;

int get_length(char *str){
    int c = 0;
    while(*str){
        c++;
        str++;
        cout<< *str << '\n';
    }
    return c;
}

int main() {
    int c=1;
    char d='A';
    printf("c %d, a %c", c, d);
}
