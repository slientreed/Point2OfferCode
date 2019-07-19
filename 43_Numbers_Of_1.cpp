
//
//  Created by mark on 2019/7/19.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：43.求1~n的所有整数中1出现的次数
 2. 思路：1. 不断对每个数字分解
         2. 找规律
 */



#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <assert.h>

#include <cstdio>
#include <fstream>
#include <map>
#include <set>

using namespace std;

int NumberOf1(unsigned int n);

// 方法1.不断对每个数字分解
int NumberOf1_sum(unsigned int n)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += NumberOf1(i);
    
    return sum;
}

// 求每个数字中1的个数
int NumberOf1(unsigned int n)
{
    int sum = 0;
    while(n)
    {
        if(n % 10 == 1)
            sum++;
        
        n /= 10;
    }
    return sum;
}



int main()
{
    
    cout << "输入数字：";
    int num;
    cin >> num;
    cout << "1~" << num << "中1的个数是：" << NumberOf1_sum(num) << endl;
    
    return 0;
}


