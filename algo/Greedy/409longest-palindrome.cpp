class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {0};

        for (char ch : s) {
            count[ch]++;
        }

        int ans = 0;
        bool hasOdd = false;

        for (int i = 0; i < 128; i++) {
            // 取出当前字符能够组成的全部字符对
            ans += count[i] / 2 * 2;

            // 存在未被使用的单个字符
            if (count[i] % 2 == 1) {
                hasOdd = true;
            }
        }

        // 最多选择一个单字符作为回文串中心
        if (hasOdd) {
            ans++;
        }

        return ans;
    }
};