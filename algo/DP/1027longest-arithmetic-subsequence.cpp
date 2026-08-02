class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<int, int>> dp(n);

        int answer = 2;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int d = nums[i] - nums[j];
                int length = 2;

                // 如果前面已经有相同公差的序列，则接在其后
                if (dp[j].count(d)) {
                    length = dp[j][d] + 1;
                }

                dp[i][d] = max(dp[i][d], length);
                answer = max(answer, dp[i][d]);
            }
        }

        return answer;
    }
};