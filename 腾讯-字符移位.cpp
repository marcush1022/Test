/*
链接：https://www.nowcoder.com/questionTerminal/7e8aa3f9873046d08899e0b44dac5e43
来源：牛客网

小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
你能帮帮小Q吗？


输入描述:


输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
  


输出描述:


对于每组数据，输出移位后的字符串。
示例1
输入

AkleBiCeilD
输出

kleieilABCD

解：冒泡排序即可
*/

#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
void bubble(string &str)
{
    int len=str.length();
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len-i-1; j++)
        {
            if((str[j]>='A' && str[j]<='Z') && (str[j+1]>='a' && str[j+1]<='z'))
                swap(str[j], str[j+1]);
        }
    }
}
 
int main()
{
    string str;
    while(cin>>str){
        bubble(str);
        cout<<str<<endl;
    }
     
    return 0;
}
