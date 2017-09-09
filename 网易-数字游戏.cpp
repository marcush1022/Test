/*
链接：https://www.nowcoder.com/questionTerminal/876e3c5fcfa5469f8376370d5de87c06
来源：牛客网

小易邀请你玩一个数字游戏，小易给你一系列的整数。你们俩使用这些整数玩游戏。每次小易会任意说一个数字出来，
然后你需要从这一系列数字中选取一部分出来让它们的和等于小易所说的数字。 例如： 如果{2,1,2,7}是你有的一系列数，
小易说的数字是11.你可以得到方案2+2+7 = 11.如果顽皮的小易想坑你，他说的数字是6，那么你没有办法拼凑出和为6 现在小易给你n个数，
让你找出无法从n个数中选取部分求和的数字中的最小数。 
输入描述:

输入第一行为数字个数n (n ≤ 20)
第二行为n个数xi (1 ≤ xi ≤ 100000)


输出描述:

输出最小不能由n个数选取求和组成的数
示例1
输入

3
5 1 2
输出

4

解：从小到大排序，一开始一块钱都凑不出来
下面，为了0~x都有，我需要来一个1元的（不然1元凑不出来）
给了你1元的，下面必须给1+1元以内的，不然2元凑不出来
如果再给一个1元的，那你现在能凑出0~2元的，接下来+1+2或者+3，都能增大范围而且不会导致中间缺一个数（4元的不行，因为凑不出3了）
——反正一直往下，直到出现第一个算不出来的值为止。
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
int getMin(vector<int> nums)
{
    int len=nums.size();
    sort(nums.begin(), nums.end());
    int miss=0;
    for(int i=0; i<len; i++)
    {
        if(nums[i]>miss+1)
            break;
        miss+=nums[i];
    }
    return miss+1;
}
 
int main()
{
    int len;
    cin>>len;
    vector<int> nums(len);
    for(int i=0; i<len; i++)
        scanf("%d", &nums[i]);
    int x=getMin(nums);
    cout<<x<<endl;
    return 0;
}
