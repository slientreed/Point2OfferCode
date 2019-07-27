
//
//  Created by mark on 2019/7/27.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：57_2. 和为s的连续序列。
 2. 思路：类似于上个双指针方法，small和big为相邻的，累计small和big之间的数字，与sum比较。
 
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

// 输入和，在1~n中找连续序列
void PrintContinuousSeq(int small, int big);
void FindContiousSeq(int sum)
{
    if(sum < 3) return;
    
    int small = 1, big = 2;
    int mid = (sum + 1) / 2;
    int cur = small + big;
    

    while(small < mid)
    {
        
        if(cur == sum)                  // 找到一组相等则输出
            PrintContinuousSeq(small,big);
        
        while(cur > sum && small < mid)      // 如果大于sum，则small向前移动
        {
            cur -= (small++);
            
            if(cur == sum)
                PrintContinuousSeq(small, big);
        }
        
        cur += (++big);        // 否则向后移动继续找
    }
    
}

// 打印两个数字之间的数
void PrintContinuousSeq(int small, int big)
{
    for(int i = small; i <= big; ++i)
        cout << i << " ";
    cout << endl;
}


int main()
{
    
    int sum;
    cout << "输入要查找的和：";
    cin >> sum;
    FindContiousSeq(sum);

    return 0;
}


