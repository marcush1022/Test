/*
链接：https://www.nowcoder.com/questionTerminal/4b24ebad2ffd4f679320fd464b2036a6
来源：牛客网

有一楼梯共m级，刚开始时你在第一级，若每次只能跨上一级或者二级，要走上m级，共有多少走法？注：规定从一级到一级有0种走法。
给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100。为了防止溢出，请返回结果Mod 1000000007的值。
测试样例：
3
返回：2

解：类似斐波纳挈数列的解法
注意是不是结果模1000000007而是每一个cur都要模1000000007
*/

class GoUpstairs {
public:
    long long countWays(int n) {
        // write code here
        if(n==1 || n==0)
            return 0;
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        long long ppre=1, pre=2, cur;
        for(int i=4; i<=n; i++)
        {
            cur=(ppre+pre)%1000000007;
            ppre=pre;
            pre=cur;
        }
        return cur;
    }
};
