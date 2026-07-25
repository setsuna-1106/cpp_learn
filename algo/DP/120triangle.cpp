class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);

        dp[0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            // 最右侧只能从上一层最右侧到达
            dp[i] = dp[i - 1] + triangle[i][i];

            // 必须从右向左更新
            for (int j = i - 1; j >= 1; j--) {
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            }

            // 最左侧只能从上一层最左侧到达
            dp[0] = dp[0] + triangle[i][0];
        }

        return *min_element(dp.begin(), dp.end());
    }
};