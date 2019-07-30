
//
//  Created by mark on 2019/7/28.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：65. 不用加减乘除做加法
 2. 思路：位运算，分三步：
         1. 不考虑进位每位相加：用异或代替
         2. 两个1会产生进位，先做与运算，在左移
         3. 把前两步结果相加 -> 重复前面两步，直到不产生进位即可
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
#include <deque>
#include <algorithm>
#include <list>

using namespace std;


int add(int num1, int num2)
{
    int sum, carry;
    do
    {
        sum = num1 ^ num2;                // 1.计算每位相加
        carry = (num1 & num2) << 1;       // 2.计算进位
        num1 = sum;
        num2 = carry;
    }while(num2 != 0);       // 3.如果进位不为0，继续前两步
    
    return num1;
}


int main()
{
    cout << "输入相加的两个数：";
    int num1,num2;
    cin >> num1 >> num2;
    cout << add(num1, num2) << endl;
    
    return 0;
}


