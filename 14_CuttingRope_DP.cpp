//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/7/3.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：14.剪绳子问题，把长度为n的绳子剪成m段，如何让每段绳子长度最大？
 2. 思路：动态规划/贪心算法
         1. 自上而下分解子问题：f(n) = max(f(i) * f(n));
         2. 自下而上求解：分别求得f(1),f(2)，...子问题的解，并用一个数组存储，供每次求更大n时调用；
 3. 扩展：
 
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int maxProductAfterCuting(int length)
{
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    
    int* products = new int[length+1];   // 记录每个子问题（每段绳子）长度的乘积
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;   //绳长为3，一刀不剪最长为3
    //products[4] = 4  // 绳长为4时，可列可不列，动态规划结果和不剪的值一样
    
    int res;
    for(int i = 4; i <= length; ++i)
    {
        int max = 0;
        for(int j = 1; j <= i / 2; ++j)    // 对i长度的每个子问题进行计算,找出i的子问题的最大值，存到对应products[i]里面，供之后使用
        {
            int product = products[j] * products[i-j];
            if(max < product)
                max = product;
            
            products[i] = max;
            
        }
    }
    
    res = products[length];
    delete[] products;
    
    return res;
    
}

int main(){

    int length;
    cout << "请输入绳子的长度：";
    cin >> length;
    int maxProduct = maxProductAfterCuting(length);
    
    cout << maxProduct << endl;
    
    return 0;
}
