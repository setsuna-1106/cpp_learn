class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        long long total = 0;
        for (int x : arr) {
            total += x;
        }
        if (total % 3 != 0) {
            return false;
        }

        long long target = total / 3;
        long long currentSum = 0;
        int count = 0;

        for (int i = 0; i < arr.size() - 1; i++) {
            currentSum += arr[i];

            if (currentSum == target) {
                count++;
                currentSum = 0;

                if (count == 2) {
                    return true;
                }
            }
        }

        return false;
    }
};