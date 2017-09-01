/*
常规的表达式求值，我们都会根据计算的优先级来计算。比如*/的优先级就高于+-。但是小易所生活的世界的表达式规则很简单，
从左往右依次计算即可，而且小易所在的世界没有除法，意味着表达式中没有/，只有(+, - 和 *)。现在给出一个表达式，
需要你帮忙计算出小易所在的世界这个表达式的值为多少 
输入描述:

输入为一行字符串，即一个表达式。其中运算符只有-,+,*。参与计算的数字只有0~9.
保证表达式都是合法的，排列规则如样例所示。


输出描述:

输出一个数，即表达式的值
示例1
输入

3+5*7
输出

56

从左往右开始读，一次读两个，一个操作符和一个数字，结果相加即可

*/

#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
int calcu(string str)
{
    int ret=0;
    ret+=str[0]-'0';
    int i=1;
    while(i<str.length())
    {
        if(!isdigit(str[i]) && isdigit(str[i+1]))
        {
            if(str[i]=='-')
                ret-=(str[i+1]-'0');
            if(str[i]=='+')
                ret+=(str[i+1]-'0');
            if(str[i]=='*')
                ret*=(str[i+1]-'0');
        }
        i+=2;
    }
    return ret;
}
 
int main()
{
    string str;
    cin>>str;
    cout<<calcu(str)<<endl;
    return 0;
}
