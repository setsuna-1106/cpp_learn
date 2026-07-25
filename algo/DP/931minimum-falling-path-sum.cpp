class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // dp[j] 表示上一行走到第 j 列的最小路径和
        vector<int> dp = matrix[0];

        for (int i = 1; i < n; i++) {
            vector<int> next(n);

            for (int j = 0; j < n; j++) {
                int minPrev = dp[j];

                // 左上角
                if (j > 0) {
                    minPrev = min(minPrev, dp[j - 1]);
                }

                // 右上角
                if (j + 1 < n) {
                    minPrev = min(minPrev, dp[j + 1]);
                }

                next[j] = matrix[i][j] + minPrev;
            }

            dp = next;
        }

        return *min_element(dp.begin(), dp.end());
    }
};