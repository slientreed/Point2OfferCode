
//
//  Created by mark on 2019/8/10.
//  Copyright © 2019年 mark. All rights reserved.
//


//题目：https://www.nowcoder.com/practice/fc72d3493d7e4be883e931d507352a4a?tpId=98&tqId=32827&tPage=1&rp=1&ru=%2Fta%2F2019test&qru=%2Fta%2F2019test%2Fquestion-ranking


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

    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    char v[4] = {'N','E','S','W'};
    
    int cur = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'R')
        {
            cur += 1;
            if(cur > 3) cur = 0;
        }
        
        if(s[i] == 'L')
        {
            cur -= 1;
            if(cur < 0) cur = 3;
        }
    }
    
    cout << v[cur] << endl;
    
    
    return 0;
}



