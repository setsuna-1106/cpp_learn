class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        vector<int> ans;
        for(int n:nums){
            sum+=n;
        }
        int index=nums.size()-1;
        while(sum>=0){
            sum-=2*nums[index];
            ans.push_back(nums[index]);
            index--;
        }
        return ans;
    }
};