
//
//  Created by mark on 2019/7/28.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：59_2. 实现一个队列，含有max函数每次O（1）取队列中的最大值。
 2. 思路：和1的方法类似，维护一个max的deque，每次出队入队进行比较，保持最大值在max队列的前面
 
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


template<typename T> class QueueWithMax
{
public:
    QueueWithMax():curIndex(0)      // 初始化当前索引全为0
    {
    }
    
    // 入队
    void push_back(T number)
    {
        while(!maxQueue.empty() && number >= maxQueue.back().number)       // 判断入队元素和之前比较，如果打大，maxQueue之前的元素直接出队
            maxQueue.pop_back();
        
        InternalData cur_data = {number,curIndex};          // 保持索引
        dataQueue.push_back(cur_data);
        maxQueue.push_back(cur_data);
        
        ++curIndex;
    }
    
    // 出队
    void pop_front()
    {
        if(maxQueue.empty())
            throw "queue is empty!";
        
        if(maxQueue.front().index == dataQueue.front().index)         // 如果maxQueue元素索引值和dataQueue中一样，则说明两个队首元素一直，maxQueue也出队
            maxQueue.pop_front();
        
        dataQueue.pop_front();
    }
    
    // 取当前队列最大值
    T max() const
    {
        if(maxQueue.empty())
            throw "queue is empty!";
        
        return maxQueue.front().number;
    }
    
    
private:
    struct InternalData     // 定义一个索引和数字的结构体
    {
        T number;
        int index;
    };
    
    deque<InternalData> dataQueue;
    deque<InternalData> maxQueue;
    int curIndex;
    
};


int main()
{
    
    QueueWithMax<int> max_queue;
    cout << "输入要入队元素的个数：";
    int sum;
    cin >> sum;
    for(int i = 0; i < sum; ++i)
    {
        int num;
        cin >> num;
        max_queue.push_back(num);
    }
    
    int max_val = max_queue.max();
    cout << "最大值是：" << max_val << endl;
    
    return 0;
}


