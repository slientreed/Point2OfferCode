
//
//  Created by mark on 2019/7/30.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 描述：输入两个数组，可以改变两个数组，改变之后使得 S = a[0]*b[0] + ... + a[n - 1]*b[n - 1]最小
 
 输入描述：输入一共三行：
         第一行为n，表示两个数组长度；
         第二行包含n个数字，空格隔开，数组a的值;
         第三行包括n个数字，空格隔开，数组b的值；
 
 输出描述：输出一行，包含一个数字，表示S的最小值。
 
 输入：3
      1  1  3
      10 30 20
 
 输出：80
 
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
    int a[100];
    int b[100];
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);         // scanf比cin快十倍以上
    
    sort(a, a + n);
    sort(b, b + n);
    
    int s = 0;
    for(int i = 0; i < n; i++)
        s += a[i] * b[n - 1 - i];
    cout << s << endl;
    
    return 0;
}


