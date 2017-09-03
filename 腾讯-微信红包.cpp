/*
链接：https://www.nowcoder.com/questionTerminal/fbcf95ed620f42a88be24eb2cd57ec54
来源：牛客网

春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。
给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。
若没有金额超过总数的一半，返回0。
测试样例：
[1,2,3,2,2],5
返回：2

解：还是用快排partition的方法
但是要判断有没有超过一半的
*/

class Gift {
public:
    int partition(vector<int> &gifts, int left, int right){
        int val=gifts[right];
        for(int i=left; i<right; i++){
            if(gifts[i]<val)
                swap(gifts[i], gifts[left++]);
        }
        swap(gifts[left], gifts[right]);
        return left;
    }
     
    bool hasHalf(vector<int> nums){
        int len=nums.size();
        map<int, int> mp;
        for(int i=0; i<len; i++){
            if(++mp[nums[i]]>(len/2))
                return true;
        }
        return false;
    }
     
    int getValue(vector<int> gifts, int n) {
        // write code here
        int pos=n/2, ans;
        int left=0, right=n-1;
        if(!hasHalf(gifts))
            return 0;
        while((ans=partition(gifts, left, right))!=pos){
            if(ans>pos)
                right=ans-1;
            else
                left=ans+1;
        }
        return gifts[pos];
    }
};
