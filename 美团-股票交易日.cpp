/*
链接：https://www.nowcoder.com/questionTerminal/3e8c66829a7949d887334edaa5952c28
来源：牛客网

在股市的交易日中，假设最多可进行两次买卖(即买和卖的次数均小于等于2)，规则是必须一笔成交后进行另一笔(即买-卖-买-卖的顺序进行)。
给出一天中的股票变化序列，请写一个程序计算一天可以获得的最大收益。请采用实践复杂度低的方法实现。
给定价格序列prices及它的长度n，请返回最大收益。保证长度小于等于500。
测试样例：
[10,22,5,75,65,80],6
返回：87

解：动态规划的解法
用两个数组，一个dp1从前往后遍历，一个dp2从后往前遍历
dp1表示在0~i元素中可获得的最大收益
dp2表示在i~len-1元素可获得的最大收益
dp1[i]+dp2[i]即表示在i之前买进卖出和i之后买进卖出的收益和
最大收益即为max(dp1[i]+dp2[i])
求dp[i]的方法同理leetCode原题
*/

class Stock  {
public:
    int maxProfit(vector<int> prices, int n) {
        // write code here
        int len=prices.size();
        if(len==0)
            return 0;
        vector<int> dp1(len);
        vector<int> dp2(len);
        int maxPro=0;
        int minPrices=prices[0];
        for(int i=1; i<len; i++)
        {
            minPrices=min(prices[i], minPrices);
            dp1[i]=max(dp1[i-1], prices[i]-minPrices);
        }
        int maxPrices=prices[len-1];
        for(int i=len-2; i>=0; i--)
        {
            maxPrices=max(prices[i], maxPrices);
            dp2[i]=max(dp2[i+1], maxPrices-prices[i]);
        }
        for(int i=0; i<len; i++)
            maxPro=max(dp1[i]+dp2[i], maxPro);
        return maxPro;
    }
};
