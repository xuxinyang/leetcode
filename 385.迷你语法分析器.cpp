/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int index = 0;
    NestedInteger deserialize(string s) {
        if (s[index] == '[') {
            index++;
            NestedInteger res;
            while (s[index] != ']') {
                if (s[index] == ',') index++;
                res.add(deserialize(s));
            }
            index++;
            return res;
        } else {
            bool negative = false;
            if (s[index] == '-') {
                negative = true;
                index++;
            }
            int res = 0;
            while (index < s.size() && isdigit(s[index])) {
                res = res * 10 + (s[index] - '0');
                index++;
            }
            if (negative) res = -res;
            return NestedInteger(res);
        }
    }
};
// @lc code=end

