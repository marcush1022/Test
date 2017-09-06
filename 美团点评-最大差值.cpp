/*
有一个长为n的数组A，求满足0≤a≤b<n的A[b]-A[a]的最大值。
给定数组A及它的大小n，请返回最大差值。
测试样例：
[10,5],2
返回：0

解：同理只能购买一次的股票操作
*/

class LongestDistance {
public:
    int getDis(vector<int> nums, int n)
    {
        int minNum=nums[0], maxDiff=0;
        for(int i=1; i<n; i++)
        {
            minNum=min(minNum, nums[i]);
            maxDiff=max(maxDiff, nums[i]-minNum);
        }
        return maxDiff;
    }
};
