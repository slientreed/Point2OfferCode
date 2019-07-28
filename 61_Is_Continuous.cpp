
//
//  Created by mark on 2019/7/28.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：61. 扑克牌的顺序。从扑克牌中抽取5张牌，判断是不是顺子 。
 2. 思路： 1. 排序数组
          2. 统计0的个数
          3. 统计相邻数字之间的空缺总数
 
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

using namespace std;


bool isContinuous(vector<int> &nums)
{
    if(nums.size() == 0)
        return false;
    
    sort(nums.begin(), nums.end());
    
    int number_zero = 0;
    int number_gap = 0;
    
    // 统计0的个数
    for(int i = 0; i < nums.size() && nums[i] == 0; i++)
        number_zero++;
    
    // 统计间隔数目
    int small = number_zero;     // 从0的下一位开始统计
    int big = small + 1;
    while(big < nums.size())
    {
        if(nums[small] == nums[big])
            return false;
        
        number_gap += nums[big] - nums[small] - 1;
        small = big;
        big++;
    }
    
    return number_gap > number_zero ? false : true;
    
}


int main()
{
    
    vector<int> nums;
    cout << "输入5张牌：";
    for(int i = 0; i < 5; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    
    for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    
    if(isContinuous(nums))
        cout << "是顺子！" << endl;
    else
        cout << "不是顺子！" << endl;
    
    return 0;
}


