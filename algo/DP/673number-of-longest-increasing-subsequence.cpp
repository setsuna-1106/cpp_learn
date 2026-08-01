class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),max=1;
        int dp[n],count[n];
        int ans=0;
        dp[0]=1,count[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            count[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]) {
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }else if(dp[j]+1==dp[i]) count[i]+=count[j];
                }
                
            }
        }
        for(int i=0;i<n;i++){
            if(dp[i]>max){
                max=dp[i];
                ans=count[i];
            }
            else if(dp[i]==max){
                ans+=count[i];
            }
        }
        return ans;
    }
};