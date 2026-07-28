#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = static_cast<int>(s.size());
        int n = static_cast<int>(t.size());

        /*
         * dp[i][j]：
         * 使用 s 的前 i 个字符组成 t 的前 j 个字符的方案数
         */
        vector<vector<unsigned long long>> dp(
            m + 1,
            vector<unsigned long long>(n + 1, 0)
        );

        /*
         * 任意字符串组成空串的方法只有一种：
         * 一个字符都不选择。
         */
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                /*
                 * 不使用 s[i - 1]。
                 */
                dp[i][j] = dp[i - 1][j];

                if (s[i - 1] == t[j - 1]) {
                    /*
                     * 额外增加：
                     * 使用 s[i - 1] 与 t[j - 1] 匹配的方案数。
                     */
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }

        return static_cast<int>(dp[m][n]);
    }
};