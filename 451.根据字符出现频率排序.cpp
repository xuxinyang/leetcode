/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for (auto c : s) {
            map[c]++;
        }
        vector<pair<int, char>> v;
        for (auto it = map.begin(); it != map.end(); it++) {
            v.push_back(make_pair(it->second, it->first));
        }
        sort(v.begin(), v.end());
        string res;
        for (auto it = v.rbegin(); it != v.rend(); it++) {
            for (int i = 0; i < it->first; i++) {
                res += it->second;
            }
        }
        return res;
    }
};
// @lc code=end

