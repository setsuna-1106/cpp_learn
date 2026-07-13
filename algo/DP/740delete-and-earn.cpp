class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        //转化为打家劫舍
        if (nums.empty()) {
            return 0;
        }

        // 找出 nums 中的最大值
        int maxValue = 0;

        for (int num : nums) {
            maxValue = max(maxValue, num);
        }

        // points[i] 表示所有数字 i 能提供的总点数
        vector<int> points(maxValue + 1, 0);

        for (int num : nums) {
            points[num] += num;
        }

        // 只有数字 0 时
        if (maxValue == 0) {
            return points[0];
        }

        // 动态规划
        vector<int> dp(maxValue + 1, 0);

        dp[0] = points[0];
        dp[1] = max(points[0], points[1]);

        for (int i = 2; i <= maxValue; i++) {
            dp[i] = max(
                dp[i - 1],
                dp[i - 2] + points[i]
            );
        }

        return dp[maxValue];
    }
};