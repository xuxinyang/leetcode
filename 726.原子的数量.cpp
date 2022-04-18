/*
 * @lc app=leetcode.cn id=726 lang=cpp
 *
 * [726] 原子的数量
 */

// @lc code=start
class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0, n = formula.size();
        auto parseAtom = [&]() -> string {
            string atom;
            atom += formula[i++];
            while (i < n && islower(formula[i]))
            {
                atom += formula[i++];
            }
            return atom;
        };
        auto parseNumber = [&]() -> int {
            if (i == n || !isdigit(formula[i])) return 1;
            int num = 0;
            while (i < n && isdigit(formula[i]))
            {
                num = num * 10 + int(formula[i++] - '0');
            }
            return num;
        };
        stack<unordered_map<string, int>> stk;
        stk.push({});
        while (i < n)
        {
            char c = formula[i];
            if (c == '(')
            {
                i++;
                stk.push({});
            }
            else if (c == ')')
            {
                i++;
                int num = parseNumber();
                auto atomNum = stk.top();
                stk.pop();
                for (auto& p : atomNum)
                {
                    stk.top()[p.first] += p.second * num;
                }
            }
            else
            {
                string atom = parseAtom();
                int num = parseNumber();
                stk.top()[atom] += num;
            }
        }
        auto &atomNum = stk.top();
        vector<pair<string, int>> pairs;
        for (auto &[atom, v] : atomNum)
        {
            pairs.emplace_back(atom, v);
        }
        sort(pairs.begin(), pairs.end());
        string ans;
        for (auto &p : pairs)
        {
            ans += p.first;
            if (p.second > 1)
            {
                ans += to_string(p.second);
            }
        }
        return ans;
    }
};
// @lc code=end

