/*
 * @lc app=leetcode.cn id=676 lang=cpp
 *
 * [676] 实现一个魔法字典
 */

// @lc code=start
class MagicDictionary {
public:
    unordered_map<int, vector<string>>mymap;
    /** Initialize your data structure here. */
    MagicDictionary() {        
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(string word : dictionary)
            mymap[word.size()].emplace_back(word);
    }
    
    bool search(string searchWord) {
        if(mymap[searchWord.size()].empty())
            return false;
        for(string word : mymap[searchWord.size()]){
            int cnt = 0;
            for(int i=0; i<searchWord.size(); i++){
                if(word[i] != searchWord[i]){
                    cnt++;
                    if(cnt > 1)
                        break;
                }
            }
            if(cnt == 1)
                return true;
        }
        return false;
    }
};


/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end

