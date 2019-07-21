
//
//  Created by mark on 2019/7/21.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：45.把数组排列成最小的数
 2. 思路：先把整数数组转化为字符串，然后对字符串数组排序，最后依次输出字符串数组。
 
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

using namespace std;


// 比较函数，比较两个字符串拼接之后的大小.(重点在于此，标志着排序的方式)
bool compare(const string &left, const string &right)
{
    string left_r = left + right;
    string right_l = right + left;

    return left_r < right_l;
}


string PringMinNumber(vector<int> number)
{

    string res = "";
    string str;
    
    vector<string> strNum;
    
    for(int i = 0; i < number.size(); i++)
    {
        str = to_string(number[i]);
        strNum.push_back(str);
    }
    
    // 对字符串按照拼接之后的大小进行排序
    sort(strNum.begin(), strNum.end(), compare);
    
    // 拼接结果
    for(int i = 0; i < strNum.size(); i++)
    {
        res += strNum[i];
    }
    
    return res;
    
}




int main()
{
    
    vector<int> numbers{3,32,321};
    string res = PringMinNumber(numbers);
    
    cout << "最小的排序是：" << res << endl;
    
    return 0;
}


