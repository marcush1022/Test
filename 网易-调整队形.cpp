/*
链接：https://www.nowcoder.com/questionTerminal/a4690c9a420b423db91b1c109c133a52
来源：牛客网

在幼儿园有n个小朋友排列为一个队伍，从左到右一个挨着一个编号为(0~n-1)。其中有一些是男生，有一些是女生，男生用'B'表示，女生用'G'表示。小朋友们都很顽皮，当一个男生挨着的是女生的时候就会发生矛盾。作为幼儿园的老师，你需要让男生挨着女生或者女生挨着男生的情况最少。你只能在原队形上进行调整，每次调整只能让相邻的两个小朋友交换位置，现在需要尽快完成队伍调整，你需要计算出最少需要调整多少次可以让上述情况最少。例如：
GGBBG -> GGBGB -> GGGBB
这样就使之前的两处男女相邻变为一处相邻，需要调整队形2次 
输入描述:

输入数据包括一个长度为n且只包含G和B的字符串.n不超过50.


输出描述:

输出一个整数，表示最少需要的调整队伍的次数
示例1
输入

GGBBG
输出

2

解：排序并记录交换次数。由于队形可能会有GGGGBBBB或BBBBGGG两种情况，因此排序两次，从小到大和从大到小，结果取最小值。
*/

#include <iostream>
#include <vector>
 
using namespace std;
 
int bubble1(string str)
{
    int len=str.length();
    int count=0;
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len-i-1; j++)
        {
            if(str[j]=='B' && str[j+1]=='G')
            {
                swap(str[j], str[j+1]);
                ++count;
            }
        }
    }
    return count;
}
 
int bubble2(string str)
{
    int len=str.length();
    int count=0;
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len-i-1; j++)
        {
            if(str[j]=='G' && str[j+1]=='B')
            {
                swap(str[j], str[j+1]);
                ++count;
            }
        }
    }
    return count;
}
 
int main()
{
    string str;
    cin>>str;
    int count1=bubble1(str);
    int count2=bubble2(str);
    cout<<min(count1, count2)<<endl;
    return 0;
}
