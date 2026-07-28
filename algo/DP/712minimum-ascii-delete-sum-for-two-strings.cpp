#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = static_cast<int>(s1.size());
        int n = static_cast<int>(s2.size());

        // dp[i][j]：
        // s1 前 i 个字符与 s2 前 j 个字符变得相等的最小删除和
        vector<vector<int>> dp(
            m + 1,
            vector<int>(n + 1, 0)
        );

        // s2 为空：只能删除 s1 的所有字符
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0]
                     + static_cast<unsigned char>(s1[i - 1]);
        }

        // s1 为空：只能删除 s2 的所有字符
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j - 1]
                     + static_cast<unsigned char>(s2[j - 1]);
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    // 相同字符可以共同保留
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 删除 s1 当前字符
                    int deleteFromS1 =
                        dp[i - 1][j]
                        + static_cast<unsigned char>(s1[i - 1]);

                    // 删除 s2 当前字符
                    int deleteFromS2 =
                        dp[i][j - 1]
                        + static_cast<unsigned char>(s2[j - 1]);

                    dp[i][j] = min(deleteFromS1, deleteFromS2);
                }
            }
        }

        return dp[m][n];
    }
};