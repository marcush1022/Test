/*
链接：https://www.nowcoder.com/questionTerminal/28c1dc06bc9b4afd957b01acdf046e69
来源：牛客网

给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
输出需要删除的字符个数。

输入描述:


输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
  


输出描述:


对于每组数据，输出一个整数，代表最少需要删除的字符个数。
示例1
输入

abcda
google
输出

2
2

解：即求最长回文子序列的长度
*/

#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int lps(string s)
{
    int len=s.length();
    vector<vector<int>> dp(len, vector<int>(len));
    for(int i=len-1; i>=0; i--)
    {
        dp[i][i]=1;
        for(int j=i+1; j<len; j++)
        {
            if(s[i]==s[j])
                dp[i][j]=dp[i+1][j-1]+2;
            else
                dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][len-1];
}
 
int main()
{
    string str;
    while(cin>>str){
        int len=str.length();
        int x=len-lps(str);
        cout<<x<<endl;
    }
     
    return 0;
}
