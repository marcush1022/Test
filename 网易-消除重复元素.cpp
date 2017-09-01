/*
链接：https://www.nowcoder.com/questionTerminal/0d241147265d4f64aacd1e2d3e46abc6
来源：牛客网

小易有一个长度为n序列，小易想移除掉里面的重复元素，但是小易想是对于每种元素保留最后出现的那个。小易遇到了困难,希望你来帮助他。 
输入描述:

输入包括两行：
第一行为序列长度n(1 ≤ n ≤ 50)
第二行为n个数sequence[i](1 ≤ sequence[i] ≤ 1000)，以空格分隔


输出描述:

输出消除重复元素之后的序列，以空格分隔，行末无空格
示例1
输入

9
100 100 100 99 99 99 100 100 100
输出

99 100

解：先去重，用个map记录元素最后出现的位置，然后将结果按此位置排序
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
 
using namespace std;
 
map<int, int> mp;
 
int clean(vector<int> &nums)
{
    int ret=0;
    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i]!=nums[i-1])
            nums[++ret]=nums[i];
    }
    return ret+1;
}
 
bool cmp(int x, int y)
{
    return mp[x]<mp[y];
}
 
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
 
    for(int i=0; i<n; i++)
    {
        scanf("%d", &nums[i]);
        mp[nums[i]]=i;
    }
    int ret=clean(nums);
    sort(nums.begin(), nums.begin()+ret, cmp);
    for(int i=0; i<ret; i++)
    {
        //cout<<"'"<<mp[nums[i]]<<"'";
        cout<<nums[i];
        if(i!=ret-1)
            cout<<" ";
    }
    return 0;
}

