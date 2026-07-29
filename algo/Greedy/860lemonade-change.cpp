class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;  // 5 美元钞票数量
        int ten = 0;   // 10 美元钞票数量

        for (int bill : bills) {
            if (bill == 5) {
                // 支付 5 美元，不需要找零
                five++;
            }
            else if (bill == 10) {
                // 需要找 5 美元
                if (five == 0) {
                    return false;
                }

                five--;
                ten++;
            }
            else { // bill == 20
                // 需要找 15 美元
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                // 否则使用三张 5 美元
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};