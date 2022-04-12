/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        dict.insert(beginWord);
        unordered_set<string> cur, next;
        cur.insert(beginWord);
        vector<vector<string>> res;
        vector<string> path;
        path.push_back(beginWord);
        int minLen = INT_MAX;
        bool found = false;
        while (!cur.empty() && !found) {
            for (auto word : cur) {
                for (int i = 0; i < word.size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        string newWord = word;
                        newWord[i] = c;
                        if (dict.count(newWord)) {
                            next.insert(newWord);
                            path.push_back(newWord);
                            if (newWord == endWord) {
                                found = true;
                                minLen = min(minLen, (int)path.size());
                            }
                        }
                    }
                }
            }
            if (found) {
                for (auto word : path) {
                    if (path.size() == minLen) res.push_back(path);
                }
            }
            cur.swap(next);
            next.clear();
            path.pop_back();
        }
        return res;
    }
};
// @lc code=end

