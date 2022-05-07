/*
 * @lc app=leetcode.cn id=1562 lang=cpp
 *
 * [1562] 查找大小为 M 的最新分组
 */

// @lc code=start
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<pair<int, int>> endpoints(n + 1, make_pair(-1, -1));
        int cnt = 0;
        int ret = -1;

        for (int i = 0; i < n; i++) {
            int left = arr[i], right = arr[i];
            if (arr[i] > 1 && endpoints[arr[i] - 1].first != -1) {
                left = endpoints[arr[i] - 1].first;
                int leftLength = endpoints[arr[i] - 1].second - endpoints[arr[i] - 1].first + 1;
                if (leftLength == m) {
                    cnt--;
                }
            }
            if (arr[i] < n && endpoints[arr[i] + 1].second != -1) {
                right = endpoints[arr[i] + 1].second;
                int rightLength = endpoints[arr[i] + 1].second - endpoints[arr[i] + 1].first + 1;
                if (rightLength == m) {
                    cnt--;
                }
            }
            int length = right - left + 1;
            if (length == m) {
                cnt++;
            }
            if (cnt > 0) {
                ret = i + 1;
            }
            endpoints[left] = endpoints[right] = make_pair(left, right);
        }
        return ret;
    }
};
// @lc code=end

