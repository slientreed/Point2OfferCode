
//
//  Created by mark on 2019/7/30.
//  Copyright © 2019年 mark. All rights reserved.
//



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
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> work(n);    // 表示n个工作对
    for(int i = 0; i < n; i++)
        cin >> work[i].first >> work[i].second;
    sort(work.begin(), work.end());
    
    vector<pair<int, int>> p(m);   // 表示n个人，第二个记录人的顺序
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
    sort(p.begin(), p.end());
    
    vector<int> res(m);
    
    
    
    for(int i = 0,j = 0; j < m; j++)
    {
        int cur = 0;
        while (i < n && work[i].first <= p[j].first)
        {     // 对每个人在工作中进行搜索
            cur = max(cur, work[i].second);
            i++;
        }
        
        res[p[j].second] = cur;
    }
    
    for(vector<int>::iterator iter = res.begin(); iter != res.end(); iter++)
        cout << *iter << endl;
    
}

