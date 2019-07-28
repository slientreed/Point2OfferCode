
//
//  Created by mark on 2019/7/28.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：63. 股票的最大利润
 2. 思路： 遍历，找出最大差值；往后找当前小值，不断往后找，求最大差值即可。
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

int maxDiff(vector<int> &nums)
{
    if(nums.size() == 0)
        return 0;
    
    int min = nums[0];
    int maxDiff = nums[1] - min;
    
    for(int i = 2; i < nums.size(); i++)
    {
        if(nums[i-1] < min)    // 更新min值
            min = nums[i-1];
        
        int curDiff = nums[i] - min;      // 往后找最大差值，如果比maxdiff大， 则更新
        if(curDiff > maxDiff)
            maxDiff = curDiff;
    }
    
    return maxDiff;
}



int main()
{
    
    vector<int> nums{9,11,8,5,7,12,16,14};
    int maxD = maxDiff(nums);
    cout << maxD << endl;
    
    return 0;
}


