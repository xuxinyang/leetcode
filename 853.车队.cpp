/*
 * @lc app=leetcode.cn id=853 lang=cpp
 *
 * [853] 车队
 */

// @lc code=start
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        map<int, int> mp;
        stack<double> st;
        int len = position.size();
        for(int i = 0; i < len; i++) mp[position[i]] = speed[i];
        for(const auto m:mp) st.push(double(target - m.first) / double(m.second));
        int out = 0;
        while(!st.empty())
        {
            double car1 = st.top();
            st.pop();
            if(st.empty())
            {
                out++;
                break;
            }
            double car2 = st.top();
            st.pop();
            if(car2 > car1) 
            {
                out++;
                st.push(car2);
            }
            else st.push(car1);
        }
        return out;
    }
};
// @lc code=end

