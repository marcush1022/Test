/*
链接：https://www.nowcoder.com/questionTerminal/c96d6acc025541ffb79c579688f8d003
来源：牛客网

给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)） 
输入描述:

输入包括一个整数n,(3 ≤ n < 1000)


输出描述:

输出对数
示例1
输入

10
输出

2

解：leetcode类似的方法。逐个判断即可
*/

#include <iostream>
#include <vector>
#include <cmath>
  
using namespace std;
  
vector<bool> isPrime(int n)
{
    vector<bool> prime(n);
    //bool *prime=new bool[n];
    for(int i=0; i<n; i++)
        prime[i]=true;
    prime[1]=false;
    int end=sqrt(n);
    for(int i=2; i<n; i++)
    {
        if(i>end)
            continue;
        for(int j=i*i; j<n; j+=i)
            prime[j]=false;
    }
    return prime;
}
  
int main()
{
    int n;
    cin>>n;
    vector<bool> prime;
    int count=0, end;
    prime=isPrime(n);
    if(n%2)
        end=(n+1)/2;
    else
        end=n/2;
    for(int i=2; i<=end; i++)
    {
        if(prime[i] && prime[n-i])
            count++;
    }
    cout<<count<<endl;
    return 0;
}
