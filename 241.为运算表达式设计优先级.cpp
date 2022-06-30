/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        if (expression.empty()) {
            return res;
        }
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        switch (expression[i]) {
                            case '+':
                                res.push_back(l + r);
                                break;
                            case '-':
                                res.push_back(l - r);
                                break;
                            case '*':
                                res.push_back(l * r);
                                break;
                        }
                    }
                }
            }
        }
        if (res.empty()) {
            res.push_back(stoi(expression));
        }
        return res;
    }
};
// @lc code=end

