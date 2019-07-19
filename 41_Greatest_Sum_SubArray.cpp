
//
//  Created by mark on 2019/7/19.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：42.连续子数组的最大和。在一个数组中，求所有数组的和的最大值。
 2. 思路：动态规划。记录两个值，当前最大值和最大值；不断向前遍历数组，当前最大值加当前元素，如果比最大值大，则更新最大值；否则最大值不变
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



bool g_InvalidInput = false;            // 定义一个全局变量，是否为无效输入

//递归思路，cur_sum不断叠加，和max_sum比较
int FindGreatestSum(vector<int> nums)
{
    if(nums.size() == 0)
    {
        g_InvalidInput = true;
        return 0;
    }
    
    int cur_sum = 0, max_sum = INT_MIN;
    for(int i = 0; i < nums.size(); i++)
    {
        if(cur_sum <= 0)         // 如果cur_sum加一个之后变小了，则舍弃掉之前，从当前元素开始累加
            cur_sum = nums[i];
        else
            cur_sum += nums[i];
        
        if(cur_sum > max_sum)
            max_sum = cur_sum;
    }
    return max_sum;
}


// 使用贪心，对上面的递归的改进：如果当前和为负数，放弃前面累加和，从下一个数继续开始；否则不断累加
int FindGreatestSum_greedy(vector<int> nums)
{
    if(nums.size() == 0)
    {
        g_InvalidInput = true;
        return 0;
    }
    
    int cur_sum = 0, max_sum = INT_MIN, max_num = INT_MIN;
    
    for(int i = 0; i < nums.size(); i++)
    {
        cur_sum += nums[i];
        
        if(cur_sum < 0)
            cur_sum = 0;
        else if(cur_sum > max_sum)
            max_sum = cur_sum;
        
        // 保存数据中的最大值，解决数组全为负的情况
        if(nums[i] > max_num)
            max_num = nums[i];
    }
    
    
    return max_sum > 0 ? max_sum : max_num;
}




int main()
{
    
    vector<int> nums{1,-2,3,10,-4,7,2,-5};
    int max_sum = FindGreatestSum(nums);
    if(g_InvalidInput)
        cout << "输入不合法！" << endl;
    else
        cout << "最大连续和是：" << max_sum << endl;
    
    return 0;
}


