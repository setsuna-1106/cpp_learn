class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len=cost.size();
        int pre1=cost[len-2];
        int pre2=cost[len-1];
        int index=len-3;

        while(index>=0){
            int temp,min;
            if(pre1<pre2) min=pre1;else min=pre2;
            temp=cost[index]+min;
            pre2=pre1;
            pre1=temp;
            --index;
        }
        if(pre1<pre2) return pre1;else return pre2;
    }
};