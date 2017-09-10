/*
链接：https://www.nowcoder.com/questionTerminal/e11bc3a213d24fc1989b21a7c8b50c3f
来源：牛客网

如果一个数列S满足对于所有的合法的i,都有S[i + 1] = S[i] + d, 这里的d也可以是负数和零,我们就称数列S为等差数列。
小易现在有一个长度为n的数列x,小易想把x变为一个等差数列。小易允许在数列上做交换任意两个位置的数值的操作,并且交换操作允许交换多次。但是有些数列通过交换还是不能变成等差数列,小易需要判别一个数列是否能通过交换操作变成等差数列 
输入描述:

输入包括两行,第一行包含整数n(2 ≤ n ≤ 50),即数列的长度。
第二行n个元素x[i](0 ≤ x[i] ≤ 1000),即数列中的每个整数。


输出描述:

如果可以变成等差数列输出"Possible",否则输出"Impossible"。
示例1
输入

3
3 1 2
输出

Possible

解：简单题。能不能组成等差数列就看排序后元素之间的差是不是相等。
*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <cstdio>
 
using namespace std;
 
int main()
{
    int n;
    bool flag=true;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        scanf("%d", &nums[i]);
    sort(nums.begin(), nums.end());
    int diff=nums[1]-nums[0];
    int tmp=diff;
    for(int i=2; i<n; i++)
    {
        tmp=nums[i]-nums[i-1];
        if(diff!=tmp)
            flag=false;
    }
    if(flag)
        cout<<"Possible"<<endl;
    else
        cout<<"Impossible"<<endl;
    return 0;
}
