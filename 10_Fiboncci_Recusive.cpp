//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/7/2.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：                   = 0                n = 0
 1. 问题：斐波那契数列 f(n) = 1                n = 1
                        = f(n-1) + f(n-2)   n > 1;
 2. 思路：递归
         循环
 3.扩展：对很多问题要学会抽象，比如青蛙跳台阶也是斐波那契数列
 */

#include <iostream>
#include <vector>
#include <stack>



using namespace std;

/*
// 递归解法
long Fibonacci(int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    
    return Fibonacci(n-1) + Fibonacci(n-2);
}
*/


// 循环解法 ： 注意到递归过程有很多重复计算，可以采用从下往上计算，依次求出f(0),f(1),f(2),...,f(n);
// time： O(n)
long Fibonacci(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    
    long fib_0 = 0;
    long fib_1 = 1;
    long fib_n;
    for(int i = 2; i <= n; ++i)
    {
        fib_n = fib_0 + fib_1;
        
        fib_0 = fib_1;          // 不断改变f(n-1)，f(n-2)的值；如果要输出前n个所有的值，用向量记录一下
        fib_1 = fib_n;
    }
    
    return fib_n;
}

int main(){

    cout << "请输入要求第几位的Fibonacci值：";
    int n;
    cin >> n;
    cout << Fibonacci(n) << endl;
    
    return 0;
}
