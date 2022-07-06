/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& a, vector<int>& b) {
    vector<pair<int, int>> vc(b.size());
    for(int i = 0; i < b.size(); i++) vc[i] = make_pair(b[i], i);
    // 排序
    sort(a.begin(), a.end()); sort(vc.begin(), vc.end());
    vector<int> ans(b.size()); int l = 0, r = b.size()-1;
    // 依次遍历a中每个数（排过序了，所以每次的a[i]都是剩余元素中最小的数），为每个数找到在b中匹配的元素
    for(int i = 0; i < b.size(); i++){
        int p = vc[l].first < a[i]? l++: r--;
        b[p] = a[i]; //这里b没有用了，暂时当一个存储结果的容器
    }
    // 将b中的结果改造成题目要求的顺序存入ans中
    for(int i = 0; i < b.size(); i++) ans[vc[i].second] = b[i];
    return ans;
}

};
// @lc code=end

