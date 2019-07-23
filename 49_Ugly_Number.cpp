
//
//  Created by mark on 2019/7/22.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：49.判断丑数。一个数只能被2，3，5整除，则这个数是丑数。
 2. 思路：1. 挨个判断，找到第1500个丑数
         2. 时间换空间，从小到大保存已经计算的丑数；然后不断乘2，3，5找大于下一个较大值。这样不用计算非丑数了
 
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

/*
// 方法1：不断在数字里搜，判断是不是丑数。

// 判断一个数是不是丑数
bool isUgly(int number)
{
    while(number % 2 == 0)
        number /= 2;
    while(number % 3 == 0)
        number /= 3;
    while(number % 5 == 0)
        number /= 5;
    
    return number == 1;          // 如果最终等于1，是丑数，否则不是
}

// 找到第index个丑数
int GetUglyNumber(int index)
{
    if(index <= 0)
        return 0;
    
    int number = 0;
    int count = 0;
    while(count < index)
    {
        number++;
        
        if(isUgly(number))
            count++;
    }
    
    return number;
}
*/

// 第二种方法：用一个数组记录已找到的丑数

int Min(int num1,int num2,int num3);

int GetUglyNumber2(int index)
{
    if(index <= 0)
        return 0;
    
    int* pUgly = new int[index];         // 开辟一个数组存放已有的丑数
    pUgly[0] = 1;
    int next_ugly = 1;               // 已找到丑数的索引
    
    int* pMul2 = pUgly;          // 下个待乘的指针
    int* pMul3 = pUgly;
    int* pMul5 = pUgly;
    
    while(next_ugly < index)
    {
        int min_ugly = Min(*pMul2 * 2, *pMul3 * 3, *pMul5 * 5);    // 去当前2，3，5相乘后的最小值，插入数组
        pUgly[next_ugly] = min_ugly;
        
        while(*pMul2 * 2 <= pUgly[next_ugly])         // 找到当前乘以2/3/5会大于的那个数,下次直接更新这个数，用于插入数组
            ++pMul2;
        while(*pMul3 * 3 <= pUgly[next_ugly])
            ++pMul3;
        while(*pMul5 * 5 <= pUgly[next_ugly])
            ++pMul5;
        
        ++next_ugly;
    }
    int ugly = pUgly[next_ugly - 1];
    delete[] pUgly;
    return ugly;
}

int Min(int num1,int num2,int num3)
{

    int min;
    min = num1 < num2 ? num1 : num2;
    min = min < num3 ? min : num3;

    return min;
}


int main()
{
    
    cout << "输入要找第几个：";
    int n;
    cin >> n;
    cout << GetUglyNumber2(n) << endl;
    
    return 0;
}


