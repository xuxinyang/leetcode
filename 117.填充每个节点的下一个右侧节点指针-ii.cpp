/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        Node* cur = root;
        while (cur) {
            Node* next = nullptr;
            Node* pre = nullptr;
            while (cur) {
                if (cur->left) {
                    if (pre) {
                        pre->next = cur->left;
                    } else {
                        next = cur->left;
                    }
                    pre = cur->left;
                }
                if (cur->right) {
                    if (pre) {
                        pre->next = cur->right;
                    } else {
                        next = cur->right;
                    }
                    pre = cur->right;
                }
                cur = cur->next;
            }
            cur = next;
        }
        return root;
    }
};
// @lc code=end

