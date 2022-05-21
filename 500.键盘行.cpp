/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        unordered_map<char, int> m;
        m['q'] = 1; m['w'] = 1; m['e'] = 1; m['r'] = 1; m['t'] = 1; m['y'] = 1; m['u'] = 1; m['i'] = 1; m['o'] = 1; m['p'] = 1;
        m['a'] = 2; m['s'] = 2; m['d'] = 2; m['f'] = 2; m['g'] = 2; m['h'] = 2; m['j'] = 2; m['k'] = 2; m['l'] = 2;
        m['z'] = 3; m['x'] = 3; m['c'] = 3; m['v'] = 3; m['b'] = 3; m['n'] = 3; m['m'] = 3;
        for (auto& word : words) {
            int row = m[word[0]];
            bool flag = true;
            for (int i = 1; i < word.size(); ++i) {
                if (m[word[i]] != row) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
// @lc code=end

