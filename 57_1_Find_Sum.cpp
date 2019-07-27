
//
//  Created by mark on 2019/7/27.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：57_1. 和为s的数字,在一个递增序列中，任意查找两个数字和为s的两个数字。
 2. 思路：1. 暴力法：固定一个，然后另一个从后向前搜索  O(n^2)
         2. 双指针法：small指针指向第一个元素，big指针指向最后一个元素。判断两个数字和与s的比较，不断移动small和big，找到两个数字；  O（n）
 
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


// 输入向量，待找的sum，以及两个整型指针，如果找到返回true，否则返回值为false
bool FindNNumbersSum(vector<int> nums, int sum, int* num1, int* num2)
{
    
    bool find = false;
    if(nums.size() == 0 || num1 == nullptr || num2 == nullptr)
        return find;
    
    int small = 0, big = nums.size() - 1;     // 定义连个指针
    
    while(small < big)     //直到small指针和big指针相遇，如果还未找到，则未找到
    {
        int cur = nums[small] + nums[big];
        
        if(cur == sum)
        {
            *num1 = nums[small];
            *num2 = nums[big];
            find = true;
            break;
        }
        else if(cur < sum)
            small++;
        else
            big--;
    }
    
    return find;
}


int main()
{
    
    vector<int> nums{1,2,4,7,11,15};
    int num1,num2;
    cout << "输入要查的和：";
    int sum;
    cin >> sum;
    bool find = FindNNumbersSum(nums, sum, &num1, &num2);
    if(find)
        cout << num1 << "+" << num2 << "=" << sum << endl;
    else
        cout << "要查找的" << sum << "不存在！" << endl;

    return 0;
}


