
//
//  Created by mark on 2019/7/28.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：62. 圆圈中最后的剩下的数字。0~n-1排成一个圈，从0开始删除第m个数字，求最后剩下的数字。
 2. 思路： 1. 使用环形链表模拟圆圈
          2. 分析每次被删的数字规律，直接计算
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


// 1. 模拟圆形链表方法，  O（mn）
int LastRemove(int n, int m)
{
    
    if(n < 1 || m < 1)
        return -1;
    
    int i = 0;
    
    list<int> nums;          // 把元素放入list中
    for(i = 0; i < n; i++)
        nums.push_back(i);
    
    list<int>::iterator cur = nums.begin();
    while(nums.size() > 1)
    {
        for(int i = 1; i < m; i++)
        {
            cur++;
            if(cur == nums.end())      // 指向末尾时候调整到链表首
                cur = nums.begin();
        }
        
        list<int>::iterator next = ++cur;   // 指向待删的后一个节点
        if(next == nums.end())
            next = nums.begin();
        
        --cur;    // 因为前面让cur加1了
        nums.erase(cur);             //nums.remove(*cur); 删除当前节点和迭代器，指向下一个迭代器；remove删除值，且返回值为空
        cur = next;
    }
    
    return *cur;
}


// 方法2：递归公式：知道n-1个人的胜利者，把第n个人加入，在数m次，就知道胜利者；f(i) = (f(i-1) + m) % i;且 f(1) = 0;
// 这样，不断递归，就可以找到第n的情况

int LastRemove_math(int n, int m)
{
    if(n < 1 || m < 1)
        return -1;
    
    int last = 0;     // 一个人的情况
    for(int i = 2; i <= n; i++)       // 循环到n
        last = (last + m) % i;        // 递归公式
    
    return last;
}



int main()
{
    
    
    int n,m;
    cout << "请输入n和m：";
    cin >> n >> m;
    int num = LastRemove_math(n, m);
    cout << num << endl;
    
    return 0;
}


