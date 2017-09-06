/*
链接：https://www.nowcoder.com/questionTerminal/b7b1ad820f0a493aa128ed6c9e0af448
来源：牛客网

C市现在要转移一批罪犯到D市，C市有n名罪犯，按照入狱时间有顺序，另外每个罪犯有一个罪行值，值越大罪越重。现在为了方便管理，市长决定转移入狱时间连续的c名犯人，同时要求转移犯人的罪行值之和不超过t，问有多少种选择的方式？ 

输入描述:

第一行数据三个整数:n，t，c(1≤n≤2e5,0≤t≤1e9,1≤c≤n)，第二行按入狱时间给出每个犯人的罪行值ai(0≤ai≤1e9)


输出描述:

一行输出答案。
示例1
输入

3 100 2
1 2 3
输出

2

//更优的O(n)解法
//解：由题意，即求数组中连续的长度为c的子序列中和小于t的数量
//直接遍历即可，先把前c个元素相加，然后逐个减去左边的加上右边的即可
*/

#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
int countSequence(vector<int> nums, int c, int t)
{
    int len=nums.size();
    int count=0, sum=0;
    int left, right;
    for(int i=0; i<c; i++)
        sum+=nums[i];
    if(sum<=t)
        ++count;
    for(int left=0, right=c; right<len; left++, right++)
    {
        sum-=nums[left];
        sum+=nums[right];
        if(sum<=t)
            ++count;
    }
    return count;
}
 
int main()
{
    int n, t, c;
    while(cin>>n>>t>>c)
    {
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        cout<<countSequence(nums, c, t)<<endl;
    }
 
    return 0;
}
