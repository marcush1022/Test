/*小易有一块n*n的棋盘，棋盘的每一个格子都为黑色或者白色，小易现在要用他喜欢的红色去涂画棋盘。
小易会找出棋盘中某一列中拥有相同颜色的最大的区域去涂画，帮助小易算算他会涂画多少个棋格。 

输入描述:

输入数据包括n+1行：

第一行为一个整数n(1 ≤ n ≤ 50),即棋盘的大小

接下来的n行每行一个字符串表示第i行棋盘的颜色，'W'表示白色，'B'表示黑色


输出描述:

输出小易会涂画的区域大小

示例1

输入: 

3
BWW
BBB
BWB

输出: 

3

直接求数组vector<string>竖着的连续最长重复元素长度即可。
*/


#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
int common(vector<string> strs, int n)
{
    int maxCom=0;
    int globeMax=0;
    int k=0;
    while(k<n)
    {
        for(int i=0; i<n; i++)
        {
            int j=i;
            while(j<n && strs[j][k]==strs[i][k])
                j++; 
            maxCom=max(j-i, maxCom);
        }
        globeMax=max(globeMax, maxCom);
        ++k;
    }
    return maxCom;
}
 
int main()
{
    int n;
    cin>>n;
    vector<string> strs(n);
    int maxCom=0;
    for(int i=0; i<strs.size(); i++)
        cin>>strs[i];
    maxCom=common(strs, n);
    cout<<maxCom<<endl;
    return 0;
}
