class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();

        vector<int> dp(n, 1);

        int ans = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (arr[j]+difference==arr[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }

            }

            ans = max(ans, dp[i]);
        }

        return ans;        
    }
};

/*
使用hash表
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;

        int answer = 0;

        for (int x : arr) {
            // 前一个元素必须是 x - difference
            dp[x] = dp[x - difference] + 1;

            answer = max(answer, dp[x]);
        }

        return answer;
    }
};
*/