
//
//  Created by mark on 2019/7/21.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：44. 数字序列中某一位数字
 2. 思路：找数字的规律。一位数有有几个数字；二位数有几个数字；三位数有几个数字；...。
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



int beginNumber(int digits);
int digitAtIndex(int index, int digits);
int countOfIntegers(int digits);

int digitAnIndex(int index)
{
    if(index < 0)
        return -1;
    
    int digits = 1;
    while(true)
    {
        int numbers = countOfIntegers(digits);      // 计算第m位有多少数字
        if(index < numbers * digits)
            return digitAtIndex(index, digits);     // 找出索引位于当前位数的哪一个
        
        index -= digits * numbers;
        digits++;
    }
    return -1;
}



// 计算m位的数字总共有多少个
int countOfIntegers(int digits)
{
    if(digits == 1)
        return 10;
    
    int count = (int)std::pow(10, digits - 1);
    return 9 * count;
}


// 确定索引位于m位数之中，用函数找出那一位数字
int digitAtIndex(int index, int digits)
{
    int number = beginNumber(digits) + index / digits;     // 在哪个m位数上
    int indexFromRight = digits - index % digits;         // 在m位数中，从右数第几位
    for(int i = 1; i < indexFromRight; ++i)
        number /= 10;
    return number % 10;
}

// 求第一个m位数的数字
int beginNumber(int digits)
{
    if(digits == 1)
        return 0;
    
    return (int)std::pow(10, digits - 1);
}




int main()
{
    
    cout << "输入一个索引：";
    int index;
    cin >> index;
    int digit = digitAnIndex(index);
    cout << "第" << index << "位是：" << digit << endl;
    
    return 0;
}


