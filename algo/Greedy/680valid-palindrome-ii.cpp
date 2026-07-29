class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                // 第一次出现不同，只能删除左边或右边的一个字符
                return check(s, left + 1, right) ||
                       check(s, left, right - 1);
            }
        }

        return true;
    }

private:
    bool check(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};