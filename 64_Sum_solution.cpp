
//
//  Created by mark on 2019/7/30.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：64. 不用乘除，循环求：1+2+3+...+n
 2. 思路：1. 构造函数：创建n次对象，调用n次构造函数的内容
         2. 递归：从n开始递减进行递归的相加运算；
                 终止条件:n为0，使其短路。短路运算0 && cout使条件为假值
         3. 位运算 + 递归
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

// 1. 使用构造函数方法
class Temp
{
public:
    Temp()
    {
        ++n;
        sum += n;
    }
    static void reset()
    {
        n = 0;
        sum = 0;
    }
    static int Getsum()
    {
        return sum;
    }
private:
    static int n;
    static int sum;

};

int Temp::n = 0;
int Temp::sum = 0;

int sum_solution1(int n)
{
    Temp::reset();
    Temp* a = new Temp[n];     // 创建n个对象，调用n次构造函数
    delete[] a;
    a = nullptr;
    
    return Temp::Getsum();
}


// 2. 递归方法，注意短路条件
int sum_Recu(int n)
{
    int res = n;
    
    n && (res += sum_Recu(n - 1));         // 短路运算，终止循环，结束递归
    return res;
}

// 3. 位运算 a*b 通过移位和加法实现

// 这里插入一个计算机计算乘法的过程，计算机内部通过位运算计算a*b的
int Mul(int a, int b)
{
    int res = 0;
    while(a != 0)
    {
        if((a & 1) != 0)      // 判断a的最后一位是否为0
            res += b;
        
        a >>= 1;
        b <<= 1;           // 和十进制的高位相加一致
    }
    return res;
}

// 去掉循环的乘法做法
int res = 0;
int mul_Recu(int a, int b)
{
    a && mul_Recu(a >> 1, b << 1);    // 递归运算
    (a & 1) && (res += b);             // 短路
    
    return res;
}

int sum_solution3(int n)
{
    //int res = 0;
    return (mul_Recu(n, n+1) >> 1);
}

int main()
{
    
    cout << "输入要求的n:";
    int n;
    cin >> n;
    cout << sum_solution3(n) << endl;
    
    return 0;
}


