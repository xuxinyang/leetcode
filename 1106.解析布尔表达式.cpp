/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 *
 * [1106] 解析布尔表达式
 */

// @lc code=start
class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        return dfs(expression);
    }
    bool dfs(string s)
    {
        if (s.size() == 1)
        {
            if (s[0] == 'f')
                return false;
            return true;
        }
        bool ans;
        bool isFirst = true;
        char flag = s[0];
        vector<string> exps = split(s.substr(2, s.size() - 3));
        for (string &exp : exps)
        {
            if (isFirst)
            {
                if (flag == '!')
                    ans = !dfs(exp);
                else if (flag == '|' || flag == '&')
                    ans = dfs(exp);
                isFirst = false;
            }
            else
            {
                if (flag == '!')
                    ans = !dfs(exp);
                else if (flag == '|')
                    ans |= dfs(exp);
                else if (flag == '&')
                    ans &= dfs(exp);
            }
        }
        return ans;
    }
    vector<string> split(string s)
    {
        int cnt = 0;
        vector<string> ans;
        int n = s.size();
        int pre = 0, cur = 0;
        while (cur < n)
        {
            if (s[cur] == '(')
                cnt++;
            else if (s[cur] == ')')
                cnt--;
            if (cnt == 0 && s[cur] == ',')
            {
                ans.push_back(s.substr(pre, cur - pre));
                pre = cur + 1;
            }
            cur++;
        }
        ans.push_back(s.substr(pre, cur - pre));
        return ans;
    }
};
// @lc code=end
