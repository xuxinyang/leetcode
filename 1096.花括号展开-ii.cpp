/*
 * @lc app=leetcode.cn id=1096 lang=cpp
 *
 * [1096] 花括号展开 II
 */

// @lc code=start
class Solution {
public:
    void add(set<string> &s, set<string> &s1)
    {
        for (auto x: s1) s.insert(x);
        s1.clear();
    }
    void mul(set<string> &s, const set<string> &s1)
    {
        if (s1.empty()) return;
        if (s.empty())
        {
            s = s1;
            return;
        }
        set<string> s2;
        for (auto t: s)
        {
            for (auto t1: s1)
            {
                s2.insert(t + t1);
            }
        }
        swap(s, s2);
    }
    void mul(set<string> &s, string &t)
    {
        if (t.empty()) return;
        if (s.empty())
        {
            s = {t};
            t.clear();
            return;
        }
        set<string> s1;
        for (auto x: s)
        {
            s1.insert(x + t);
        }
        t.clear();
        swap(s, s1);
    }
    set<string> parse(const string &exp, int l, int r)
    {
        set<string> res;
        set<string> s;
        string t;
        int i = l;
        while (i <= r)
        {
            if (exp[i] == ',')
            {
                mul(s, t), add(res, s);
            }
            else if (exp[i] == '{')
            {
                int l = i;
                int brace = 1;
                while (brace > 0 && ++i <= r)
                {
                    brace += exp[i] == '{';
                    brace -= exp[i] == '}';
                }
                mul(s, t);
                mul(s, parse(exp, l + 1, i - 1));
            }
            else
            {
                t += exp[i];
            }
            ++i;
        }
        mul(s, t);
        add(res, s);
        return res;
    }
    vector<string> braceExpansionII(string expression) {
        auto s = parse(expression, 0, expression.size() - 1);
        return vector<string> (s.begin(), s.end());
    }
};
// @lc code=end

