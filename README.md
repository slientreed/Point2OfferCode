# Point2OfferCode
《剑指offer》刷题代码   -2019.6.25

### 1. 说明
1. 个人刷剑指offer书的代码仓库，可能有错和不完善的地方，努力改进
2. C++语言，Xcode编辑器
3. 实现方法，测试用例可能不全面，慢慢完善

### 2. 进度 (计划三周 6.25 - 7.20)
日期 | 题目 | 算法内容 | C++学习
--- | ---  | ---    |  ----
6.25  | 03 | 数组    |
6.29 | 04;05 |数组;字符串 | [C++的几个输入用法](https://github.com/slientreed/Point2OfferCode/blob/master/Cplusplus_Basic_Operation/2_C%2B%2B%E8%BE%93%E5%85%A5%E8%BE%93%E5%87%BA%E7%9A%84%E5%AD%A6%E4%B9%A0.md)
6.30 | 06 | [链表](https://doc.bccnsoft.com/docs/cppreference/cpplist_details.html)/栈 | [结构体中.和 ->的区别](https://blog.csdn.net/ShenYuanLuo/article/details/51146140)
7.1 | 07;[08](https://github.com/slientreed/Point2OfferCode/blob/master/08_Next_TreeNode.cpp);[09](https://github.com/slientreed/Point2OfferCode/blob/master/09_stack_to_queue.cpp) | 二叉树;[代码参考](https://github.com/gatieme/CodingInterviews/tree/master/006-%E9%87%8D%E5%BB%BA%E4%BA%8C%E5%8F%89%E6%A0%91); 队列，栈| 先序，中序，后序遍历;[模板类写法](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/09_QueueWithTwoStacks/Queue.h)，[cin输入](https://github.com/slientreed/Point2OfferCode/blob/master/09_stack_to_queue.cpp)
7.2 | 10 | [递归](https://github.com/slientreed/Point2OfferCode/blob/master/10_Fiboncci_Recusive.cpp) | 
7.3 | 11 ,12,13,14| [二分查找(11)](https://github.com/slientreed/Point2OfferCode/blob/master/11_Find_Min_in_RotareArray.cpp);[回溯(12,13)](https://github.com/slientreed/Point2OfferCode/blob/master/12_String_Path_inMatrix.cpp) ;[动态规划(14)](https://github.com/slientreed/Point2OfferCode/blob/master/14_CuttingRope_DP.cpp)| ;数组;
7.4 | 15 | [位运算(15)](https://github.com/slientreed/Point2OfferCode/blob/master/15_Binary_Operation.cpp) | 逻辑操作 | 

### 3. 学习总结

1. 04-05题：
* [C++的cin输入用法，包括字符串输入，cin,cin.get(),cin.getline(),getline()等](https://github.com/slientreed/Point2OfferCode/blob/master/Cplusplus_Basic_Operation/2_C%2B%2B%E8%BE%93%E5%85%A5%E8%BE%93%E5%87%BA%E7%9A%84%E5%AD%A6%E4%B9%A0.md).  -2019.6.29

2. 06题学习：    -2019.6.30
* C++基础：[结构体 .和 ->的区别](https://blog.csdn.net/ShenYuanLuo/article/details/51146140),结构的表达式用 .，结构体的指针用 ->。
* 算法：[链表list](http://www.cplusplus.com/reference/list/list/list/)：[参考1](https://doc.bccnsoft.com/docs/cppreference/cpplist_details.html)，[参考2](https://www.cnblogs.com/scandy-yuan/archive/2013/01/08/2851324.html)

3. 08题学习：   — 2019.7.1
* 二叉树的结构，先序中序后序遍历在此复习一遍
* 如何构建二叉树：生成二叉树节点，并按要求连接成一个二叉树。[参考了原书作者代码](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/08_NextNodeInBinaryTrees/NextNodeInBinaryTrees.cpp)
* 加深对树，以及函数功能的测试代码编写。[具体看代码](https://github.com/slientreed/Point2OfferCode/blob/master/08_Next_TreeNode.cpp)

4. 09题学习： - 2019.7.1
* 栈，对列的实现和熟悉，用栈实现队列操作
* 有时间实现一些用队列实现栈
* [参考原书代码，好好写成模板类](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/09_QueueWithTwoStacks/Queue.h)
* cin连续输入的问题，while(cin >> a)终止条件：文件终止符（ctrl+D/ctrl+Z）;非法输入（要求int，输入其他）。[cin终止参考](https://blog.csdn.net/LYJ_viviani/article/details/52229517)

5. [11题学习](https://github.com/slientreed/Point2OfferCode/blob/master/11_Find_Min_in_RotareArray.cpp)   - 2019.7.3
* 二分法比较了解，其中有当首尾和mid三者指针值相等的时候，只能用顺序查找，这点逻辑要注意

6. [12题总结](https://github.com/slientreed/Point2OfferCode/blob/master/12_String_Path_inMatrix.cpp)  - 2019.7.3
* 回溯法：适用每步有多个选项的问题，不断递归实现，不行返回上一步继续递归下去；比如二维矩阵找路径，人在二维方格运动这种问题。
* 今天对回溯的理解还不够， 代码基本是[参考原书代码](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/12_StringPathInMatrix/StringPathInMatrix.cpp),加深理解如何理解拆分问题，如何递归遍历每步的选项
* 同时对C++基础比如数组，字符串的有要求，包括边界条件和遍历rows,cols的完整性，要多看这个代码.

7. [14题总结](https://github.com/slientreed/Point2OfferCode/blob/master/14_CuttingRope_DP.cpp)  - 2019.7.3
* 动态规划和贪心策略：主要要明白动态规划的适应问题范围；同时明白自上而下分析和自下而上实现
* 对贪心算法有些不太清楚，需要看怎么用，以及贪婪策略如何选取
* - [ ] 14题中，有时间再回过来练习一下，怎么把对应最大值的cut方法记录下来。

8. [15题总结](https://github.com/slientreed/Point2OfferCode/blob/master/15_Binary_Operation.cpp)  - 2019.7.4
* 位运算的5种运算：&,|,^,<<,>>.(与，或，异或，左移，右移)。
* 每个整数都是以二进制存储，需要操作二进制时，可以直接对整数进行运算，即使运算二进制。
* **一个很好的思路：把整数减1再和原来的整数做&运算，得到的结果相当于把整数二进制表示中最右边的一位1变成0**
### 4. 相应计划
