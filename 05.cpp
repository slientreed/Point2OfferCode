//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/6/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：替换空格，实现函数把字符串中的每个空格替换成 %20(因为space的ascii是32,换成十六进制是20)
 2. 思路：从后往前替换，减少字符移动数量  time:O（n）
 3. 实现：首先计算字符串的长度len，并统计space的个数，最后字符串长度为 len+2*space(替换后多2个字符)；
         然后使用两个指针，一个记录原长度尾，一个记录新字符串长度尾，开始往前复制，碰到space原指针停住，增加 %20；
         最后直到字符串头结束;
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void ReplaceBlank(char string[], int length);
int main(){

    //输入并接收一个字符串
    // string str;
    // getline(cin, str);   // 返回指针类型
    
    cout << "请输入要替换的字符串：";
    //输入并接收一个字符串
    char str[100];
    cin.getline(str, 50);  // 返回string类型
    cout << "替换前的字符串是：" << str << endl;
    
    ReplaceBlank(str, 100);
    cout << "替换后的字符串是：" << str << endl;
    
    return 0;
}


void ReplaceBlank(char string[], int length){

    if(string == nullptr || length == 0)
        return;
    
    // 计算原有字符串的长度，并统计空格符的长度
    int original_length = 0;
    int number_blank = 0;
    int i = 0;
    
    while(string[i] != '\0')
    {
        ++original_length;
        if(string[i] == ' ')
            ++number_blank;
        
        ++i;
    }
    
    
    // 求得替换空格符后的字符串长度
    int new_length = original_length + 2 * number_blank;
    if(new_length > length)  // 字符串数组空间要足够大
        return;
    
    // 双指针
    int index_origin = original_length;
    int index_new = new_length;
    
    while(index_origin >= 0 && index_origin < index_new)
    {
        if(string[index_origin] ==' ')
        {
            string[index_new--] = '0';
            string[index_new--] = '2';
            string[index_new--] = '%';
        }
        else
        {
            string[index_new--] = string[index_origin];
        }
    
        --index_origin;
    }
    
}








