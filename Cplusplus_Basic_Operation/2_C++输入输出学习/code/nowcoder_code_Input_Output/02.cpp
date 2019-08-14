
//
//  Created by mark on 2019/8/10.
//  Copyright © 2019年 mark. All rights reserved.
//


//题目：https://www.nowcoder.com/practice/51dcb4eef6004f6f8f44d927463ad5e8?tpId=98&tqId=32825&tPage=1&rp=1&ru=%2Fta%2F2019test&qru=%2Fta%2F2019test%2Fquestion-ranking



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
    
    long long int left, right;
    //cin >> left >> right;
    //int res = 0;
    
    while(cin >> left >> right)
    {
        int res = 0;
        for(long long int i = left; i <= right; i++)
        {
            if((i+1)*i/2 % 3 == 0)         // 计算一个数每位的和
                res++;
        }
        
        cout << res << endl;
    }
}



