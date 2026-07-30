class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 排序，让负数排在前面
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            } else {
                break;
            }
        }
        
        // 如果还有剩余的操作次数
        if (k % 2 == 1) {
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }
        
        // 计算数组和
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        return sum;
    }
};