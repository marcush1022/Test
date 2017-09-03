/*
链接：https://www.nowcoder.com/questionTerminal/b1112516673e463c9ed8943ae96e53f6
来源：牛客网

给出两个字符串（可能包含空格）,找出其中最长的公共连续子串,输出其长度。 
输入描述:

输入为两行字符串（可能包含空格），长度均小于等于50.


输出描述:

输出为一个整数，表示最长公共连续子串的长度。
示例1
输入

abcde
abgde
输出

2

解：动态规划，子串要求连续
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
 
using namespace std;
 
int lcs(string str1, string str2)
{
    int len1=str1.length();
    int len2=str2.length();
 
    int m[len1+1][len2+1];
    int count=0;
    for(int i=0; i<=len1; i++)
    {
        for(int j=0; j<=len2; j++)
        {
            if(i==0 || j==0)
                m[i][j]=0;
            else if(str1[i-1]==str2[j-1])
            {
                m[i][j]=m[i-1][j-1]+1;
                count=max(m[i][j], count);
            }
            else
                m[i][j]=0;
        }
    }
    return count;
}
 
int main()
{
    string str1, str2;
    getline(cin,str1);
    getline(cin,str2);
    cout<<lcs(str1, str2)<<endl;
    return 0;
}

//若为子序列
int lcs(string str1, string str2)
{
    int len1=str1.length();
    int len2=str2.length();
 
    int m[len1+1][len2+1];
    int count=0;
    for(int i=0; i<=len1; i++)
    {
        for(int j=0; j<=len2; j++)
        {
            if(i==0 || j==0)
                m[i][j]=0;
            else if(str1[i-1]==str2[j-1])
                m[i][j]=m[i-1][j-1]+1;
            else
                m[i][j]=max(m[i-1][j], m[i][j-1]);
        }
    }
    return m[len1][len2];
}
