class Solution {
public:
    set<string> ss;
    
    void dfs(string& cur, string& str, vector<bool>& vis) {
        if(cur.size() == str.size()) {
            ss.insert(cur);
            return;
        }
        for(int i = 0; i < str.size(); ++i) {
            if(vis[i])
                continue;
            vis[i] = true;
            cur += str[i];
            dfs(cur, str, vis);
            cur.pop_back();
            vis[i] = false;
        }
    }
    vector<string> Permutation(string& str) {
        vector<string> res;
        if(str.empty())
            return res;
        string cur;
        vector<bool> vis(str.size(), 0);
        dfs(cur, str, vis);
        return vector<string>({ss.begin(), ss.end()});
    }
};