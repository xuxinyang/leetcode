/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> vals;
    vector<int>::iterator it;
    void dfs(const vector<NestedInteger> &nestedList) {
        for (const auto &n : nestedList) {
            if (n.isInteger()) vals.push_back(n.getInteger());
            else dfs(n.getList());
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        it = vals.begin();
    }
    
    int next() {
        return *it++;
    }
    
    bool hasNext() {
        return it != vals.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

