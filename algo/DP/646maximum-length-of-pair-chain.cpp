class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(), pairs.end());
        int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]&&dp[j]+1>dp[i]) dp[i]=dp[j]+1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]>ans) ans = dp[i];
        }
        return ans;
    }
};