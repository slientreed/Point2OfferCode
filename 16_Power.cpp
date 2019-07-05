
//
//  Created by mark on 2019/7/5.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：16. 数值的整数次方，实现函数 double power(double base, int exponent),求base的exponent次方。（c语言里面有个power库函数）
 2. 思路：直接求会出现考虑不全面的问题：
                                1. base为0的情况；
                                2. 指数exponent为0和负数的情况；
 */


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

bool equal(double a, double b); // 判断浮点数是否相等
double Power_unsigned(double base, unsigned int exponent);  // 计算正整数次幂power
double Power_unsigned_fast(double base, unsigned int exponent);

// Power函数
double Power(double base, int exponent)
{
    if(exponent == 0)   // 当指数为0，任何数的0次方还是1；
        return 1.0;
    
    if(equal(base,0.0) && exponent < 0)
        cout << "0不能做分母" << endl;
    
    double res = 1.0;
    if(exponent > 0)
        res = Power_unsigned_fast(base, exponent);
    else
    {
        res = Power_unsigned_fast(base, -exponent);
        res = 1 / res;
    }
    
    return res;
}


// 判断两个浮点数是否相等equal(float a,float b);
bool equal(double a, double b)
{
    if(fabs(a - b) < 0.0001)
        return true;
    else
        return false;
}

// 计算无符号正整数的power
double Power_unsigned(double base, unsigned int exponent)
{
    double res = 1.0;
    for(int i = 1; i <= exponent; ++i)
        res *= base;
    
    return res;
}

// 优化时间的poer_unsigned()函数
double Power_unsigned_fast(double base, unsigned int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent == 1)     // 递归的终止条件
        return base;
    
    double res = Power_unsigned_fast(base, exponent >> 1); // 递归，每次乘以之前的n/2次幂;
    res *= res;
    
    if(exponent & 0x1 == 1)   // 判断exponent是奇数的话，还要多乘以一个base本身
        res *= base;
    
    return res;
}




int main(){

    int base, exponent;
    cout << "请输入base: ";
    cin >> base;
    cout << "请输入exponent: ";
    cin >> exponent;
    cout << "base的exponent次幂值是：" << Power(base,exponent) << endl;
    
    return 0;
}


