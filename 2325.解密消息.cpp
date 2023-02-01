/*
 * @lc app=leetcode.cn id=2325 lang=cpp
 *
 * [2325] 解密消息
 */

// @lc code=start
class Solution {

public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> ump;
        char a = 'a';
        for (int i = 0; i < key.size(); i++)
        {
            if (key[i] == ' ') continue;
            if (ump.count(key[i]) == 1) continue;
            ump[key[i]] = a;
            a = char(a + 1);
        }

        string ans = "";
        for (int i = 0; i < message.size(); i++)
        {
            if (message[i] == ' ') ans += ' ';
            else ans += ump[message[i]];
        }
        return ans;
    }
};
// @lc code=end

