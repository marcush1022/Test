/*
链接：https://www.nowcoder.com/questionTerminal/f3aaf8fedcea43c6b12a11710068726b
来源：牛客网

度度熊想去商场买一顶帽子，商场里有N顶帽子，有些帽子的价格可能相同。度度熊想买一顶价格第三便宜的帽子，问第三便宜的帽子价格是多少？ 
输入描述:

首先输入一个正整数N（N <= 50），接下来输入N个数表示每顶帽子的价格（价格均是正整数，且小于等于1000）


输出描述:

如果存在第三便宜的帽子，请输出这个价格是多少，否则输出-1
示例1
输入

10
10 10 10 10 20 20 30 30 40 40
输出

30

解：排序+去重
*/

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int dup(vector<int> &nums)
{
    int ret=0;
    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i]!=nums[i-1])
            nums[++ret]=nums[i];
    }
    if(ret+1<3)
        return -1;
    else
        return nums[2];
}
 
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        scanf("%d", &nums[i]);
    int val=dup(nums);
    cout<<val<<endl;
    return 0;
}
