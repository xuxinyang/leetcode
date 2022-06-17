/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 判断 t 是否是 s 的子序列

        int n = s.size(), m = t.size();
        
        // 如果 t 长度大于 s，一定不是子序列
        if(m > n) return false;

        // 记录当前 s 中匹配到了哪个位置
        int i = 0;
        for(char ch : t) {
            while(i < n && s[i] != ch) i++;
            if(i >= n) return false;

            // 此时 s[i] = ch，下次要从 s[i + 1] 开始匹配
            i++;
        }

        return true;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [&](string &a, string &b) {
            if(a.size() == b.size()) return a < b;
            return a.size() > b.size();
        });

        for(string &t : dictionary) {
            if(isSubsequence(s, t)) return t;
        }
        return "";
    }
};
// @lc code=end

