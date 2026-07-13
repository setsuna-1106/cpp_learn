class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;
        int pre1=1;
        int pre2=1;
        for(int i=3;i<=n;i++){
            int temp=pre1+pre2;
            pre1=pre2;
            pre2=temp;
        }
        return pre2;
    }
};