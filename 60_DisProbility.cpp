
//
//  Created by mark on 2019/7/28.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：60. n个骰子的点数。n个骰子，所有朝上一面的点数和为s，输入n，打印出所有s可能的值的概率。
 2. 思路：1. 递归方法：n个骰子和等于前n-1个点数和，再加第n个；结束条件：n=1，此时某个点数和出现的次数+1；
         2. 动态规划：
 
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

using namespace std;



int g_maxValue = 6;

void Probability_Core(int original, int current, int sum, int* pPro);
void Probability(int number, int* pPro);


void PrintProbability(int number)
{
    if(number < 1)
        return;
    
    int maxSum = number * g_maxValue;
    int* pPro = new int[maxSum - number + 1];       // 建一个数组，存放所有可能出现的值，并初始化为0
    for(int i = number; i <= maxSum; i++)
        pPro[i-number] = 0;
    
    Probability(number, pPro);
    
    int total = pow((double)g_maxValue, number);    // 计算总的可能性，6的n次方
    for(int i = number; i <= maxSum; i++)
    {
        double ratio = (double)pPro[i - number] / total;
        cout << ratio << " ";
    }
    cout << endl;
    
    delete[] pPro;
}


//
void Probability(int number, int* pPro)
{
    for(int i = 1; i <= g_maxValue; i++)             // 分别1~6每个点数的可能性
        Probability_Core(number, number, i, pPro);
}


void Probability_Core(int original, int current, int sum, int* pPro)
{
    if(current == 1)
        pPro[sum - original]++;
    else
    {
        for(int i = 1; i <= g_maxValue; i++)
            Probability_Core(original, current - 1, i + sum, pPro);
    }
}



int main()
{

    PrintProbability(5);
    
    return 0;
}


