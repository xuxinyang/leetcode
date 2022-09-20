/*
 * @lc app=leetcode.cn id=816 lang=cpp
 *
 * [816] 模糊坐标
 */

// @lc code=start
class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        for (int i = 1; i < s.size() - 2; ++i) {
            string firstInt = s.substr(1, i);
            string secondInt = s.substr(i + 1, s.size() - i - 2);
            vector<string> firsts = addPoint(firstInt);
            vector<string> seconds = addPoint(secondInt);
            if (legit_int(firstInt) && legit_int(secondInt)) {
                res.push_back(make_coord(firstInt, secondInt));
            }
            if (legit_int(firstInt)) {
                for (auto& second : seconds) {
                    res.push_back(make_coord(firstInt, second));
                }
            }
            if (legit_int(secondInt)) {
                for (auto& first : firsts) {
                    res.push_back(make_coord(first, secondInt));
                }
            }
            for (auto& first : firsts) {
                for (auto& second : seconds) {
                    res.push_back(make_coord(first, second));
                }
            }
        }
        return res;
    }
    inline string make_coord(string& first, string& second) {
        return "(" + first + ", " + second + ")";
    }
    inline bool legit_int(string& s) {
        return s.size() == 1 || s[0] != '0';
    }
    vector<string> addPoint(string s) {
        vector<string> res;
        if (s[s.size() - 1] == '0') return res;
        if (s[0] == '0') {
            s.insert(1, ".");
            res.push_back(s);
        }
        else {
            for (int i = 1; i < s.size(); ++i) {
                string tmp = s;
                tmp.insert(i, ".");
                res.push_back(tmp);
            }
        }
        return res;
    }
};

// @lc code=end

