class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            // 当前地块为空，并且左右相邻位置都没有花
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == size - 1 || flowerbed[i + 1] == 0)) {

                flowerbed[i] = 1;  // 在当前位置种花
                n--;

                // 已经种够 n 朵
                if (n == 0) {
                    return true;
                }
            }
        }

        return n <= 0;
    }
};