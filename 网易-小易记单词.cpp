/*
链接：https://www.nowcoder.com/questionTerminal/0b821b5d214445388eade1d304b976b2
来源：牛客网

小易参与了一个记单词的小游戏。游戏开始系统提供了m个不同的单词，小易记忆一段时间之后需要在纸上写出他记住的单词。小易一共写出了n个他能记住的单词，如果小易写出的单词是在系统提供的，将获得这个单词长度的平方的分数。注意小易写出的单词可能重复，但是对于每个正确的单词只能计分一次。 
输入描述:

输入数据包括三行：

第一行为两个整数n(1 ≤ n ≤ 50)和m(1 ≤ m ≤ 50)。以空格分隔

第二行为n个字符串，表示小易能记住的单词，以空格分隔，每个单词的长度小于等于50。

第三行为m个字符串，系统提供的单词，以空格分隔，每个单词的长度小于等于50。


输出描述:

输出一个整数表示小易能获得的分数
示例1
输入

3 4
apple orange strawberry
strawberry orange grapefruit watermelon
输出

136

解：用set, set2存系统单词，set1存写出的系统里有的非重复单词，然后遍历set1把长度累加即可
难点在字符串处理
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
 
using namespace std;
 
int main()
{
    int n, m;
    scanf("%d %d",&n, &m);
    set<string> s1, s2;
    string str1, str2;
    cin.get();
    getline(cin, str1);
    getline(cin, str2);
    int pos1=0, pos2;
    for(int i=0; i<m; i++)
    {
        pos2=str2.find(' ', pos1);
        s2.insert(str2.substr(pos1, pos2-pos1));
        pos1=pos2+1;
    }
    pos1=0;
    for(int i=0; i<n; i++)
    {
        pos2=str1.find(' ', pos1);
        string tmp=str1.substr(pos1, pos2-pos1);
        if(s2.find(tmp)!=s2.end())
            s1.insert(tmp);
        pos1=pos2+1;
    }
    int grade=0;
    for(set<string>::iterator it=s1.begin(); it!=s1.end(); it++)
    {
        int len=(*it).size();
        grade+=len*len;
    }
    cout<<grade<<endl;
    return 0;
}
