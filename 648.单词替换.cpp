/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
class Trie{
    public:
        vector<Trie*> children;
        bool isEnd;
        Trie():children(26),isEnd(false){}
        void insert(string word){
            Trie* node=this;
            for(char ch:word){
                if(!node->children[ch-'a'])node->children[ch-'a']=new Trie();
                node=node->children[ch-'a'];
            }
            node->isEnd=1;
        }
        string find(string word){
            string ans;
            Trie* node=this;
            for(char ch:word){
                if(node->children[ch-'a']){
                    ans+=ch;
                    node=node->children[ch-'a'];
                }
                else break;
                if(node->isEnd)return ans;
            }
            return node->isEnd?ans:"";
        }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss;
        ss<<sentence;
        string str;
        string ans;
        Trie *root=new Trie();
        for(string &temp:dictionary)root->insert(temp);
        while(ss>>str){
            string res=root->find(str);
            if(res.size())ans+=res;
            else ans+=str;
            ans+=' ';
        }
        return ans.substr(0,ans.size()-1);
    }
};
// @lc code=end

