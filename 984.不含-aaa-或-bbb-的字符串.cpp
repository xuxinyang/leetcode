/*
 * @lc app=leetcode.cn id=984 lang=cpp
 *
 * [984] 不含 AAA 或 BBB 的字符串
 */

// @lc code=start
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s = "";
        if (a > b)
            while (a != 0 && b != 0)
               s += "ab", a-=1, b-=1;
        else 
            while (a!= 0 && b != 0)
                s += "ba", a-=1, b-=1;
        string ans;
        if (a != 0) {
            for (size_t i = 0; i < s.size(); i++) {
                if (s[i] == 'a')
                {
                    ans += "a";
                    if (a != 0) ans += "a", a--;
                }
                else ans += "b";
            }
            ans.append(a, 'a');
        } else if (b != 0)
        {
            for (size_t i = 0; i < s.size(); i++) {
                if (s[i] == 'b')
                {
                    ans += "b";
                    if (b != 0) {
                        ans += "b";
                        b--;
                    }
                } else ans += "a";

            }
            ans.append(b, 'b');
        }
        else return s;
        return ans;
    }
};
// @lc code=end

