/*
链接：https://www.nowcoder.com/questionTerminal/df51567da86c456bb962ad58d91804ca
来源：牛客网

小易最近在数学课上学习到了集合的概念,集合有三个特征：1.确定性 2.互异性 3.无序性.
小易的老师给了小易这样一个集合：
S = { p/q | w ≤ p ≤ x, y ≤ q ≤ z }
需要根据给定的w，x，y，z,求出集合中一共有多少个元素。小易才学习了集合还解决不了这个复杂的问题,需要你来帮助他。 
输入描述:

输入包括一行：
一共4个整数分别是w(1 ≤ w ≤ x)，x(1 ≤ x ≤ 100)，y(1 ≤ y ≤ z)，z(1 ≤ z ≤ 100).以空格分隔


输出描述:

输出集合中元素的个数
示例1
输入

1 10 1 1
输出

10

用map
*/

#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
int set(int w, int x, int y, int z)
{
    map<float, int> mp;
    int count=0;
    for(float p=w; p<=x; p++)
    {
        for(float q=y; q<=z; q++)
        {
            if(!mp[p/q])
            {
                mp[p/q]++;
                ++count;
            }
        }
    }
    return count;
}
 
int main()
{
    int w, x, y, z;
    scanf("%d %d %d %d", &w, &x, &y, &z);
    int ret=set(w, x, y, z);
    cout<<ret<<endl;
    return 0;
}
