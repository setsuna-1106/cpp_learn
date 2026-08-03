class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();

        vector<int> dp(n, 1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (obstacles[j] <= obstacles[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans[i] = dp[i];
        }

        return ans;
    }
};
/*
使用tail方法
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> tail;
        vector<int> ans;

        for (int height : obstacles) {
            // 找到第一个严格大于 height 的位置
            auto pos = upper_bound(tail.begin(), tail.end(), height);

            int length = pos - tail.begin() + 1;
            ans.push_back(length);

            if (pos == tail.end()) {
                tail.push_back(height);
            } else {
                *pos = height;
            }
        }

        return ans;
    }
};
*/