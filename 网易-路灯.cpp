/*
链接：https://www.nowcoder.com/questionTerminal/62cdf520b9d94616b6644ac03a0306ff
来源：牛客网

一条长l的笔直的街道上有n个路灯，若这条街的起点为0，终点为l，第i个路灯坐标为ai ，每盏灯可以覆盖到的最远距离为d，为了照明需求，
所有灯的灯光必须覆盖整条街，但是为了省电，要是这个d最小，请找到这个最小的d。

输入描述:

每组数据第一行两个整数n和l（n大于0小于等于1000，l小于等于1000000000大于0）。第二行有n个整数(均大于等于0小于等于l)，为每盏灯的坐标，
多个路灯可以在同一点。


输出描述:

输出答案，保留两位小数。
示例1
输入

7 15
15 5 3 7 9 14 0
输出

2.50

解：遍历求最大间隔，注意路灯首尾与街道首尾的距离也要算在内
*/

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
double minD(vector<double> nums, double l)
{
    double maxDiff=0;
    int len=nums.size();
    sort(nums.begin(), nums.end());
    for(int i=1; i<len; i++)
        maxDiff=max(nums[i]-nums[i-1], maxDiff);
    double tmp=max(l-nums[len-1], nums[0]);
    return max(maxDiff/2.0, tmp);
}
 
int main()
{
    int n, l;
    while(cin>>n>>l)
    {
        vector<double> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        //cout<<(double)minD(nums)<<endl;
        double minDiff=minD(nums, l);
        printf("%.2lf\n", minDiff);
    }
 
    return 0;
}
