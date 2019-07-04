//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/7/4.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：15.二进制中1的个数，输入一个整数，输出该整数二进制中1的个数
 2. 思路：1. 转换成二进制，逐个统计法
         2. 按位运算法
 3. 扩展：
 
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
// 1.计算二进制，统计1的个数方法
int NumberOf1(int num)
{
    int count = 0;
    while(num >= 2)
    {
        int a = 0;
        a = num % 2;
        if(a == 1)
            ++count;
        num /= 2;
    }
    if(num == 1)
        ++count;
    return count;
}
*/

/*
//2. 位运算法：把数字n和flag=1做位运算，判断最低位是不是1；然后1左移一位得到2，和n与判断倒数第二位是不是1；如此知道flag溢出int,移动int变成二进制32次
int NumberOf1(int num)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(flag & num)
            ++count;
        
        flag = flag << 1;
    }
    
    return count;
}
*/


// 3. 改进的为位运算方法：把n-1和n相与，会把n最右边的1全变成0；看n变成0用了多少次，n就有多少个1；（这个挺巧妙的，只需要与1的位数次）
int NumberOf1(int num)
{
    int count = 0;
    while(num)
    {
        ++count;             // num不为0则至少有一个1;
        num = num & (num - 1);     // 把n最右边的1变成0;
    }
    return count;
}


int main(){

    int num;
    cout << "请输入一个正整数：";
    cin >> num;
    int count = NumberOf1(num);
    cout << "二进制后1的个数是：" << count << endl;
    
    return 0;
}



/*
// --------------------------------------------------------------------------------------------------------------------------------
// 书中一个习题：两个整数m,n，计算需要改变m二进制的多少位才能得到n；（1.求这两个数的异或；2.统计异或结果中1的个数）
// --------------------------------------------------------------------------------------------------------------------------------

int ManyofDiff(int m, int n)
{
    int tmp;
    tmp = m ^ n;
    int count = NumberOf1(tmp);
    return count;
}

int main(){
    int m,n;
    cout << "请输入要比较的两个数：";
    cin >> m >> n;
    int count = ManyofDiff(m, n);
    cout << "两个数不同的位数是：" << count << endl;
}
*/
