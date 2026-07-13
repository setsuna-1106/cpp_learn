class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len==1) return nums[0];
        int pre1=nums[0];
        int pre2=(nums[0]>nums[1])? nums[0]:nums[1];

        for(int i=2;i<len;i++){
            int temp=(pre1+nums[i]>pre2) ? pre1+nums[i]:pre2;
            pre1=pre2;
            pre2=temp;
        }
        return (pre1>pre2)? pre1:pre2;
    }
};