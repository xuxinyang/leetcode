/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> map;
        queue<Node*> q;
        q.push(node);
        map[node] = new Node(node->val);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for (auto n : cur->neighbors) {
                if (map.find(n) == map.end()) {
                    map[n] = new Node(n->val);
                    q.push(n);
                }
                map[cur]->neighbors.push_back(map[n]);
            }
        }
        return map[node];
    }
};
// @lc code=end

