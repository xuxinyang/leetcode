/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;
        for (auto e : employees) {
            m[e->id] = e;
        }
        return dfs(m, id);
    }
    int dfs(unordered_map<int, Employee*>& m, int id) {
        int res = m[id]->importance;
        for (auto sub : m[id]->subordinates) {
            res += dfs(m, sub);
        }
        return res;
    }
};
// @lc code=end

