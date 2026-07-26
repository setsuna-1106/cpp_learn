class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // word1 的前 i 个字符变为空串：删除 i 次
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }

        // 空串变为 word2 的前 j 个字符：插入 j 次
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({
                        dp[i - 1][j] + 1,     // 删除
                        dp[i][j - 1] + 1,     // 插入
                        dp[i - 1][j - 1] + 1  // 替换
                    });
                }
            }
        }

        return dp[m][n];
    }
};