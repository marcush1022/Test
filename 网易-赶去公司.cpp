/*
链接：https://www.nowcoder.com/questionTerminal/5c7657015d3d49369c49dd047e80b526
来源：牛客网

终于到周末啦！小易走在市区的街道上准备找朋友聚会，突然服务器发来警报,小易需要立即回公司修复这个紧急bug。假设市区是一个无限大的区域，每条街道假设坐标是(X，Y)，小易当前在(0，0)街道，办公室在(gx,gy)街道上。小易周围有多个出租车打车点，小易赶去办公室有两种选择，一种就是走路去公司，另外一种就是走到一个出租车打车点，然后从打车点的位置坐出租车去公司。每次移动到相邻的街道(横向或者纵向)走路将会花费walkTime时间，打车将花费taxiTime时间。小易需要尽快赶到公司去，现在小易想知道他最快需要花费多少时间去公司。 
输入描述:

输入数据包括五行:

第一行为周围出租车打车点的个数n(1 ≤ n ≤ 50)

第二行为每个出租车打车点的横坐标tX[i] (-10000 ≤ tX[i] ≤ 10000)

第三行为每个出租车打车点的纵坐标tY[i] (-10000 ≤ tY[i] ≤ 10000)

第四行为办公室坐标gx,gy(-10000 ≤ gx,gy ≤ 10000),以空格分隔

第五行为走路时间walkTime(1 ≤ walkTime ≤ 1000)和taxiTime(1 ≤ taxiTime ≤ 1000),以空格分隔


输出描述:

输出一个整数表示，小易最快能赶到办公室的时间
示例1
输入

2
-2 -2
0 -2
-4 -2
15 3
输出

42

分别计算各路径打车所需要的时间，记录最小值，然后与走路需要的时间比较即可。
水题
*/

#include <iostream>
#include <vector>
using namespace std;
 
int getWt(int walkTime, int targetX, int targetY)
{
    int wt;
    wt=(abs(targetX)+abs(targetY))*walkTime;
    return wt;
}
 
int getMinTt(int taxiTime, int walkTime, vector<vector<int>> points, int targetX, int targetY)
{
    int minTime=2147483647, time=0;
    for(int i=0; i<points[0].size(); i++)
    {
        time=0;
        time+=(abs(points[0][i])+abs(points[1][i]))*walkTime;
        time+=(abs(targetX-points[0][i])+abs(targetY-points[1][i]))*taxiTime;
        minTime=min(minTime, time);
    }
    return minTime;
}
 
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> points(2, vector<int>(n));
    for(int i=0; i<n; i++)
        cin>>points[0][i];
    for(int i=0; i<n; i++)
        cin>>points[1][i];
    int targetX, targetY;
    cin>>targetX>>targetY;
    int walkTime, taxiTime;
    cin>>walkTime>>taxiTime;
    int wt=getWt(walkTime, targetX, targetY);
    int tt=getMinTt(taxiTime, walkTime, points, targetX, targetY);
    cout<<min(wt, tt)<<endl;
    return 0;
}
