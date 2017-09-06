/*
链接：https://www.nowcoder.com/questionTerminal/e637331ec6254a74a863ccb9040444c4
来源：牛客网

小东和三个朋友一起在楼上抛小球，他们站在楼房的不同层，假设小东站的楼层距离地面N米，球从他手里自由落下，
每次落地后反跳回上次下落高度的一半，并以此类推知道全部落到地面不跳，求4个小球一共经过了多少米？(数字都为整数)
给定四个整数A,B,C,D，请返回所求结果。
测试样例：
100,90,80,70
返回：1020

解：数学题，注意结果要加ceil
*/

class Balls {
public:
    double mile(double n)
    {
        double cnt=0;
        cnt+=n;
        n/=2.0;
        while(n)
        {
            cnt+=(n*2.0);
            n/=2.0;
        }
        return cnt;
    }
  
    int calcDistance(int A, int B, int C, int D) {
        // write code here
        double sum=mile(A+B+C+D);
        return ceil(sum);
    }
};
