
//
//  Created by mark on 2019/7/30.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 描述：抢劫最大金额
 
 输入描述：输入n+1行， 第一行包括两个数字n和d，n:银行数量，d:约定的距离
         下面n行，每行两个数字：a,b：表示坐标和金额。
 
 输出描述：一个数字表示最大值
 
 
 输入：
 输出：
 
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

int main()
{
    
    pair<int, int> p[1000];      // 使用STL库函数维护一个pair键值对.前一个值表示坐标，后一个值表示值
    int n, d;
    cin>>n>>d;
    for(int i = 0; i < n; i++)
        scanf("%d%d", &p[i].first, &p[i].second);
    
    sort(p,p+n);    //对银行坐标进行排序
    int maxV = -1;
    int rpos = n - 1;     // 双指针
    int res = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        while(rpos > i && (p[rpos].first - p[i].first >= d))  // 从后向前遍历，找到（i,rpos）区间的最大值
        {
            maxV = max(maxV, p[rpos].second);
            rpos--;
        }
        if(maxV != -1)
            res = max(res, maxV + p[i].second);
    }
    
    cout << res << endl;
    
    return 0;
}


