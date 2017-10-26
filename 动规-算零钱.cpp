/*
链接：https://www.nowcoder.com/questionTerminal/185dc37412de446bbfff6bd21e4356ec
来源：牛客网

有一个数组changes，changes中所有的值都为正数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，对于一个给定值x，
请设计一个高效算法，计算组成这个值的方案数。
给定一个int数组changes，代表所以零钱，同时给定它的大小n，另外给定一个正整数x，请返回组成x的方案数，保证n小于等于100且x小于等于10000。
测试样例：
[5,10,25,1],4,15
返回：6
测试样例：
[5,10,25,1],4,0
返回：1

解：动态规划，把已经计算过的结果记录防止重复计算。
建立二维数组dp, dp[i][j]表示只能使用0~i拼出j有几种方法。
dp[i][j]包含：
dp[i-1][j](不使用当前k)...........1
和：
dp[i-1][j-k]
dp[i-1][j-2k]
dp[i-1][j-3k]
...
(至少一张当前k).............2
合并1和2得：
dp[i][j]=dp[i-1,j]+dp[i,j-k], k为当前值。
*/

class Exchange {
public:
    int countWays(vector<int> changes, int n, int x) {
        // write code here
        vector<vector<int>> dp(n, vector<int>(x+1));
        int rows=dp.size(), cols=dp[0].size();
        for(int i=0; i<rows; i++)
            dp[i][0]=1;
        for(int j=1; j*changes[0]<=x; j++)
            dp[0][j*changes[0]]=1;
        for(int i=1; i<rows; i++)
        {
            for(int j=1; j<=x; j++)
            {
                dp[i][j]=dp[i-1][j];
                dp[i][j]+=(j-changes[i]>=0?dp[i][j-changes[i]]:0);
            }
        }
        return dp[rows-1][x];
    }
};
