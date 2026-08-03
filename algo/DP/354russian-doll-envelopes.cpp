class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0]) {
                     return a[0] < b[0];
                 }
                 return a[1] < b[1];
             });

        vector<int> dp(n, 1);

        int answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[j][0] < envelopes[i][0] &&
                    envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            answer = max(answer, dp[i]);
        }

        return answer;
    }
};
/*
使用先排序再使用tail法求最长子序列
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 宽度升序；宽度相同时，高度降序
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0]) {
                     return a[0] < b[0];
                 }

                 return a[1] > b[1];
             });

        vector<int> tail;

        for (const vector<int>& envelope : envelopes) {
            int height = envelope[1];

            auto position = lower_bound(
                tail.begin(),
                tail.end(),
                height
            );

            if (position == tail.end()) {
                tail.push_back(height);
            } else {
                *position = height;
            }
        }

        return static_cast<int>(tail.size());
    }
};
*/