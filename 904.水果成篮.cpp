/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int max = INT_MIN;
        int i = 0;
        int cnt = 0;
        for (int j = 0; j < fruits.size(); ++j) {
            if (find(fruits.begin() + i, fruits.begin() + j, fruits[j]) == fruits.begin() + j) cnt++;
            while (cnt > 2) 
            {
                max = max > j - i ? max:j-i;
                for (int m = j - 1; m >= 0; m--)
                {
                    if (fruits[m] != fruits[j-1]) {
                        i = m + 1;
                        cnt = 2;
                        break;
                    }
                }
            }
            max = max > j - i + 1? max:j-i+1;
        }
        return max;
    }
};
// @lc code=end

