
//
//  Created by mark on 2019/7/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：56_数组中数字出现的次数。数组中除了两个数字，其他都出现了两次，找出这两个数字。O(n)
 2. 思路：1. 如果一个数组中只有一个非重复的数字，其他都是两次/偶数次，则使用异或可以解决。对所有数组元素进行异或，最后的值就是非重复
         2. 但是两个非重复元素，考虑把数组分成两段，每段只有一个非重复元素，其他都有两个重复元素；
         3. 怎么分：对数组元素异或，得到两个非重复元素异或的结果；找到结果数组第一个为1的位置，即为n位，然后以每个数字第n位是不是1分成两个数组即可
 
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


// 1. 对所有元素异或
// 2. 找异或的结果为1的位数
// 3. 以位数是否为1划分数组成两个子数组，然后在子数组内分别异或，得到两个不重复值。(如果是多个，就划分位多个数组)

int FindFirst1(int num);
bool isBit1(int num, int index);

void FindNumsAppearOnce(vector<int> data, int* num1, int* num2)
{
    if(data.size() == 0)
        return;
    
    int result_OR = 0;
    for(int i = 0; i < data.size(); ++i)
        result_OR ^= data[i];
    
    int index_1 = FindFirst1(result_OR);        // 找1的位置
    
    *num1 = *num2 = 0;
    for(int j = 0; j < data.size(); ++j)
    {
        if(isBit1(data[j], index_1))            // 判断index_1位是否为1
            *num1 ^= data[j];
        else
            *num2 ^= data[j];
    }
}


// 找从右边开始，1的位置
int FindFirst1(int num)
{
    int index = 0;
    while((num & 1) == 0 && (index < 8 * sizeof(int)))       // 最后一位是否为1
    {
        num = num >> 1;   // 右移一位
        index++;
    }
    return index;
}

// 看当前数的index_1位是否为1
bool isBit1(int num, int index)
{
    num = num >> index;     // 右移数位，然后判断
    return (num & 1);
}


int main()
{
    
    vector<int> data{2,4,3,6,3,2,5,5};
    int num1,num2;
    FindNumsAppearOnce(data, &num1, &num2);
    cout << num1 << " " << num2 << endl;
    
    return 0;
}


