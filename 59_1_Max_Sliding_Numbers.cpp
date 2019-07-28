
//
//  Created by mark on 2019/7/27.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：59_1. 滑动窗口的最大值。给定一个数组和滑动窗口大小，找出所有滑动窗口的最大值。
 2. 思路：1. 暴力法：每次在滑动窗口内比较，如果数组大小为n，滑动窗口为k， 复杂度 ：O(nk);
         2. 看成队列，每次添加相当于在末尾添加新的数字，窗口滑动相当于出栈。符合栈的特点先进先出，如何找到队列的最大值；（30题中用O(1)找到栈的最大值，然后用两个栈实现一个队列。 复杂度：O(n)）
         3. 存入一个两端开口的队列（两端都可以删除元素），进行每次只存入可能最大的元素。（重要是要判断当前最大值是否已经滑出窗口）
 
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


// 3.使用STL库函数，每次只把可能成为滑动窗口最大值的数值存入一个两端开口的队列。对于刚来的元素n,队列前面比n小，直接移除队列;比n大，判断是否还在队列里面，不在则移除队列。
// 返回值：保存每个滑动窗口的最大值向量；
// 参数：向量引用，以及滑动窗口大小
vector<int> maxInWindows(const vector<int>& nums, int size)
{
    vector<int> maxInWindows;
    
    if(nums.size() >= size && size >= 1)
    {
        deque<int> index;
        for(int i = 0; i < size; i++)
        {
            while(!index.empty() && nums[i] >= nums[index.back()])      // 如果队列不空，且当前比较值比窗口最大值大，则从后一直出队，留下最大值
                index.pop_back();
            
            index.push_back(i);                // 从后入队当前值
        }
        
        for(int i = size; i < nums.size(); i++)
        {
            maxInWindows.push_back(nums[index.front()]);        // 每次先存入前个滑动窗口的最大值。
            
            while(!index.empty() && nums[i] >= nums[index.back()])   // 当前值和队列从后出队值比较，如果大于，则说明当前队中的大值肯定会被替换，一直从后出队
                index.pop_back();
            if(!index.empty() && index.front() <= (i - size))        // 说明当前最大值已经不在滑动窗口范围内了
                index.pop_front();
            
            index.push_back(i);                      // 从后入队其索引
        }
        
        maxInWindows.push_back(nums[index.front()]);        // 存入最后一个元素
    }
    
    return maxInWindows;
}



int main()
{
    
    vector<int> nums{2,3,4,2,6,2,5,1};
    vector<int> res = maxInWindows(nums, 3);
    
    for(vector<int>::iterator iter = res.begin(); iter != res.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    
    return 0;
}


