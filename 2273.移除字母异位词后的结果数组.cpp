/*
 * @lc app=leetcode.cn id=2273 lang=cpp
 *
 * [2273] 移除字母异位词后的结果数组
 */

// @lc code=start
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        unordered_map<string, int> m;
        for (string word : words) {
            string key = word;
            sort(key.begin(), key.end());
            if (m.find(key) == m.end()) {
                m[key] = res.size();
                res.push_back(word);
            } else {
                res[m[key]] = word;
            }
        }
        return res;
    }
};
// @lc code=end

