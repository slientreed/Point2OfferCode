
//
//  Created by mark on 2019/8/10.
//  Copyright © 2019年 mark. All rights reserved.
//


//题目：https://www.nowcoder.com/practice/bf877f837467488692be703735db84e6?tpId=98&tqId=32831&tPage=1&rp=1&ru=%2Fta%2F2019test&qru=%2Fta%2F2019test%2Fquestion-ranking


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

/*
void dfs(vector<int> &weight,int size,  int sum, int pos, int cap, int* count)
{
    if(sum <= cap)
        (*count)++;
    for(int i = pos + 1; i < size; i++)
        dfs(weight,size, sum + weight[i], i, cap, count);
}


int main()
{
    
    int n,cap, sum = 0;
    int count = 0;
    cin >> n >> cap;
    vector<int> weight(n);
    for(int i = 0; i < n; i++)
    {
        cin >> weight[i];
        sum += weight[i];
    }
    
    if(sum <= cap)  // 如果商品总量小于背包容量
        count = pow(2, n);
    else
    {
        sort(weight.begin(), weight.end());
        dfs(weight,weight.size(), 0, 0, cap, &count);    // 深搜，
    }
    
    cout << count << endl;
    
    return 0;
}
*/



// 递归思路， 参考：https://www.nowcoder.com/questionTerminal/bf877f837467488692be703735db84e6?f=discussion
//递推公式：state(i,w) = state(i-1,w) + state(i-1,w-v[i])


int f(int n, int cap, vector<int> &res)
{
    if(n == 1)
    {
        if(res[n] <= cap)
            return 2;
        else
            return 1;
    }
    
    return f(n - 1, cap, res) + f(n - 1, cap - res[n], res);
}


int main()
{
    int n,cap;
    cin >> n >> cap;
    vector<int> res(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> res[i];
    
    cout << f(n, cap, res) << endl;
    
}


