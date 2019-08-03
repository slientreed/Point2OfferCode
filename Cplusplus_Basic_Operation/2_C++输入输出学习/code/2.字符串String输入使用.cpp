
//
//  Created by mark on 2019/7/30.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 描述：
 
 输入描述：一行输入，包含非空字符串，长度为n
 
 输出描述：输出一个字母。小写
 
 输入：xaCZY
 
 输出：a
 
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
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);       // 把字符串变成小写
    int pos[26] = {0};
    for( int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        pos[c - 'a'] = i;
    }
    
    char res = 'z';
    int rpos = s.size() - 1;
    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        rpos = min(rpos, pos[c - 'a']);
        res = min(res, c);
        if(i >= rpos) break;
    }
    
    cout << res << endl;
    
    return 0;
}


