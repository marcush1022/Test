/*
链接：https://www.nowcoder.com/questionTerminal/b0fbb688d01a4f2c8c17e5efd85d5824
来源：牛客网

给定一组非负整数组成的数组h，代表一组柱状图的高度，其中每个柱子的宽度都为1。 在这组柱状图中找到能组成的最大矩形的面积（如图所示）。 入参h为一个整型数组，代表每个柱子的高度，返回面积的值。


输入描述:

输入包括两行,第一行包含一个整数n(1 ≤ n ≤ 10000)
第二行包括n个整数,表示h数组中的每个值,h_i(1 ≤ h_i ≤ 1,000,000)


输出描述:

输出一个整数,表示最大的矩阵面积。
示例1
输入

6
2 1 5 6 2 3
输出

10

解：二重遍历
*/

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int getMin(vector<int> nums, int left, int right)
{
    int index=left, minVal=nums[left];
    for(int i=left+1; i<=right; i++)
    {
        if(nums[i]<minVal)
        {
            minVal=nums[i];
            index=i;
        }
    }
    return index;
}
 
int area(vector<int> nums)
{
    int len=nums.size();
    int index, maxArea=0;
    int minNum=nums[0];
    for(int i=0; i<len; i++)
    {
        minNum=nums[i];
        for(int j=i; j<len; j++)
        {
            minNum=min(minNum, nums[j]);
            int tmp=(j-i+1)*minNum;
            maxArea=max(maxArea, tmp);
        }
    }
    return maxArea;
}
 
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    cout<<area(nums)<<endl;
    return 0;
}
