class Solution {
public:
    int climbStairs(int n) {
        // if (n <= 0) return 0;
        // if (n == 1) return 1;
        // if (n == 2) return 2;

        // return climbStairs(n - 1) + climbStairs(n - 2);
        //使用递归，时间开销大

        //DP
        if(n<=0) return 0;
        if(n<=2) return n;

        int pre1=1;
        int pre2=2;
        for(int i=3;i<=n;i++){
            int temp=pre1+pre2;
            pre1=pre2;
            pre2=temp;
        }
        return pre2;
    }
};