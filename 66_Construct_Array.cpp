
//
//  Created by mark on 2019/7/30.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：66. 构建乘积数组。给定一个数组A，返回一个数组B,数组B中的元素B[i]是除了A[i]之外的连乘值
 2. 思路：具体参考原书：定义 C[i] = C[i-1] * A[i-1],自上而下计算所有A[i];定义 D[i] = D[i+1] * A[i+1] 自下而上计算 B[i] = C[i] * D[i]
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


vector<int> multiply(vector<int> &arr)
{
    
    if(arr.size() < 1)
        throw "没有数据！";
    
    vector<int> res(arr.size());
    res[0] = 1;
    for(int i = 1; i < arr.size(); i++)        // 自前向后计算C[i] = C[i-1] * A[i-1]
        res[i] = res[i - 1] * arr[i - 1];
    
    int temp = 1;
    for(int i = arr.size() - 2; i >= 0; i--)    // 自后向前计算 D[i] = C[i+1] * A[i+1]
    {
        temp *= arr[i + 1];
        res[i] *= temp;
    }
    
    return res;
}



int main()
{
    
    vector<int> arr{1,2,3,4,5};
    vector<int> res = multiply(arr);
    for(vector<int>::iterator iter = res.begin(); iter != res.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    
    return 0;
}


