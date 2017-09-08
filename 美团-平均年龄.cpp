/*
链接：https://www.nowcoder.com/questionTerminal/3745638815d04c26babcfc463c25478c
来源：牛客网

已知某公司总人数为W，平均年龄为Y岁(每年3月末计算，同时每年3月初入职新人)，假设每年离职率为x，x>0&&x<1,每年保持所有员工总数不变进行招聘，新员工平均年龄21岁。 
从今年3月末开始，请实现一个算法，可以计算出第N年后公司员工的平均年龄。(最后结果向上取整)。 
输入描述:

输入W Y x N


输出描述:

输出第N年后的平均年龄
示例1
输入

5 5 0.2 3
输出

15

解：数学题，列方程计算
注意y每年需要加1
*/

#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
int age(double w, double y, double x, double N)
{
    double sum=w, i=0, ave=y;
    while(N--)
    {
        y=x*21+(1-x)*(y+1);
    }
    return ceil(y);
}
int main()
{
    double w, y, x, N;
    while(cin>>w>>y>>x>>N){
        cout<<age(w, y, x, N)<<endl;
    }
     
    return 0;
}
