/*
链接：https://www.nowcoder.com/questionTerminal/e016ad9b7f0b45048c58a9f27ba618bf
来源：牛客网

有一个整数数组，请你根据快速排序的思路，找出数组中第K大的数。
给定一个整数数组a,同时给定它的大小n和要找的K(K在1到n之间)，请返回第K大的数，保证答案存在。
测试样例：
[1,3,5,2,2],5,3
返回：2

解：用快排的partition
*/

class Finder {
public:
    int partition(vector<int> &nums, int left, int right)
    {
        int val=nums[right];
        for(int i=left; i<right; i++)
        {
            if(nums[i]<val)
                swap(nums[i], nums[left++]);
        }
        swap(nums[left], nums[right]);
        return left;
    }
  
    int findKth(vector<int> nums, int len, int k)
    {
        int left=0, right=len-1;
        int ans=0, pos=len-k;
        while((ans=partition(nums, left, right))!=pos)
        {
            if(ans>pos)
                right=ans-1;
            else
                left=ans+1;
        }
        return nums[pos];
    }
  
};
