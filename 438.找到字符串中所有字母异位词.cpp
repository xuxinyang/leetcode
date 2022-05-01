/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size()) {
            return res;
        }
        unordered_map<char, int> map;
        for (char c : p) {
            map[c]++;
        }
        int left = 0, right = 0;
        int count = p.size();
        while (right < s.size()) {
            char c = s[right];
            if (map.count(c)) {
                map[c]--;
                if (map[c] == 0) {
                    count--;
                }
            }
            right++;
            while (count == 0) {
                if (right - left == p.size()) {
                    res.push_back(left);
                }
                char d = s[left];
                if (map.count(d)) {
                    map[d]++;
                    if (map[d] > 0) {
                        count++;
                    }
                }
                left++;
            }
        }
        return res;
    }
};
// @lc code=end

