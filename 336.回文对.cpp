/*
 * @lc app=leetcode.cn id=336 lang=cpp
 *
 * [336] 回文对
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> dict;
        for (int i = 0; i < words.size(); ++i) {
            dict[words[i]] = i;
        }
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].size(); ++j) {
                string str1 = words[i].substr(0, j);
                string str2 = words[i].substr(j);
                if (isPalindrome(str1)) {
                    string str2r = str2;
                    reverse(str2r.begin(), str2r.end());
                    if (dict.count(str2r) && dict[str2r] != i) {
                        res.push_back({i, dict[str2r]});
                    }
                }
                if (isPalindrome(str2)) {
                    string str1r = str1;
                    reverse(str1r.begin(), str1r.end());
                    if (dict.count(str1r) && dict[str1r] != i) {
                        res.push_back({dict[str1r], i});
                    }
                }
            }
        }
        return res;
    }
private:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};
// @lc code=end

