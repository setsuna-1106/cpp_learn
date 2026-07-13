class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;
        int pre1=0;
        int pre2=1;
        int pre3=1;
        for(int i=3;i<=n;i++){
            int temp=pre1+pre2+pre3;
            pre1=pre2;
            pre2=pre3;
            pre3=temp;
        }
        return pre3;
    }
};