/*
链接：https://www.nowcoder.com/questionTerminal/d66442d58616473dafb91b168d8ebd4d
来源：牛客网

大富翁游戏，玩家根据骰子的点数决定走的步数，即骰子点数为1时可以走一步，点数为2时可以走两步，点数为n时可以走n步。求玩家走到第n步（n<=骰子最大点数且是方法的唯一入参）时，总共有多少种投骰子的方法。 
输入描述:

输入包括一个整数n,(1 ≤ n ≤ 6)


输出描述:

输出一个整数,表示投骰子的方法
示例1
输入

6
输出

32

类似青蛙跳台阶的方法;
设目的地为n;
先看第一次扔，可以扔出 1,2,...,n-1, n 的数字;
若扔1，剩下的走法是f(n-1);
扔2剩f(n-2);
扔n-1剩f(1);
扔n为1;
综上:
f(n)=f(n-1)+f(n-2)+...+f(1)+1, (n>=1)
*/

#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int ret=pow(2, n-1);
    cout<<ret<<endl;
    return 0;
}
