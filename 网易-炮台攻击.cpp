/*
链接：https://www.nowcoder.com/questionTerminal/f821a39207cd43518ccddb27fee0481d
来源：牛客网

兰博教训提莫之后,然后和提莫讨论起约德尔人,谈起约德尔人,自然少不了一个人,那 就是黑默丁格------约德尔人历史上最伟大的科学家. 
提莫说,黑默丁格最近在思考一个问题:黑默丁格有三个炮台,炮台能攻击到距离它R的敌人 (两点之间的距离为两点连续的距离,例如(3,0),(0,4)之间的距离是5),
如果一个炮台能攻击 到敌人,那么就会对敌人造成1×的伤害.黑默丁格将三个炮台放在N*M方格中的点上,并且给出敌人 的坐标. 问:那么敌人受到伤害会是多大?

输入描述:

第一行9个整数,R,x1,y1,x2,y2,x3,y3,x0,y0.R代表炮台攻击的最大距离,(x1,y1),(x2,y2),
(x3,y3)代表三个炮台的坐标.(x0,y0)代表敌人的坐标.


输出描述:

输出一行,这一行代表敌人承受的最大伤害,(如果每个炮台都不能攻击到敌人,输出0×)
示例1
输入

1 1 1 2 2 3 3 1 2
输出

2x

解：计算点之间距离即可
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
  
using namespace std;
  
class Point
{
    public:
    int x;
    int y;
  
    Point(int a, int b){x=a; y=b;}
    int dis(Point &other)
    {
        int tmp=pow(this->x-other.x, 2)+pow(this->y-other.y, 2);
        return sqrt(tmp);
    }
};
  
int main()
{
    vector<int> nums(9);
    while(scanf("%d %d %d %d %d %d %d %d %d", &nums[0],&nums[1],&nums[2],&nums[3],&nums[4],&nums[5],&nums[6],&nums[7],&nums[8])!=EOF)
    {
        int r=nums[0];
        Point t1(nums[1], nums[2]);
        Point t2(nums[3], nums[4]);
        Point t3(nums[5], nums[6]);
        Point e(nums[7], nums[8]);
        int count=0;
        if(t1.dis(e)<r)
            count++;
        if(t2.dis(e)<r)
            count++;
        if(t3.dis(e)<r)
            count++;
        cout<<count<<"x"<<endl;
    }
    return 0;
}
