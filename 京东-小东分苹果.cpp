/*
链接：https://www.nowcoder.com/questionTerminal/532d89889b974506a0805062fd1089fb
来源：牛客网

果园里有一堆苹果，一共n头(n大于1小于9)熊来分，第一头为小东，它把苹果均分n份后，多出了一个，它扔掉了这一个，拿走了自己的一份苹果，
接着第二头熊重复这一过程，即先均分n份，扔掉一个然后拿走一份，以此类推直到最后一头熊都是这样(最后一头熊扔掉后可以拿走0个，也算是n份均分)。
问最初这堆苹果最少有多少个。
给定一个整数n,表示熊的个数，返回最初的苹果数。保证有解。
测试样例：
2
返回：3

解：模拟拿苹果的过程即可，先拿走一个再拿走m/n，如果最后拿完cnt等于熊数的话就是解
*/

class Apples {
public:
    int getInitial(int n) {
        // write code here
        int m, cnt=0;
        for(int m=n+1; ;m+=n)
        {
            cnt=0;
            int tmp=m;
            while(tmp%n==1)
            {
                tmp-=1;
                tmp-=tmp/n;
                cnt++;   
            }
            if(cnt==n)
                return m;
        }
    }
};
