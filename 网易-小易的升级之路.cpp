/*
链接：https://www.nowcoder.com/questionTerminal/fe6c73cb899c4fe1bdd773f8d3b42c3d
来源：牛客网

小易经常沉迷于网络游戏.有一次,他在玩一个打怪升级的游戏,他的角色的初始能力值为 a.在接下来的一段时间内,他将会依次遇见n个怪物,
每个怪物的防御力为b1,b2,b3...bn. 如果遇到的怪物防御力bi小于等于小易的当前能力值c,那么他就能轻松打败怪物,并 且使得自己的能力值增加bi;
如果bi大于c,那他也能打败怪物,但他的能力值只能增加bi 与c的最大公约数.那么问题来了,在一系列的锻炼后,小易的最终能力值为多少?

输入描述:

对于每组数据,第一行是两个整数n(1≤n<100000)表示怪物的数量和a表示小易的初始能力值.
第二行n个整数,b1,b2...bn(1≤bi≤n)表示每个怪物的防御力


输出描述:

对于每组数据,输出一行.每行仅包含一个整数,表示小易的最终能力值
示例1
输入

3 50
50 105 200
5 20
30 20 15 40 100
输出

110
205

解：简单数组处理，重点在怎么求最大公约数
*/

#include <iostream>
#include <algorithm>
  
using namespace std;
  
int maxDiv(int x, int y)
{
    if(x<y)
        return maxDiv(y, x);
    if(y==0)
        return x;
    else
        return maxDiv(x-y, y);
}
int main()
{
    int n, power;
    while(scanf("%d %d",&n,&power)!=EOF)
    {
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            scanf("%d", &nums[i]);
        for(int i=0; i<n; i++)
        {
            if(nums[i]>power)
                power+=maxDiv(nums[i], power);
            else
                power+=nums[i];
        }
        cout<<power<<endl;
    }
    return 0;
}
