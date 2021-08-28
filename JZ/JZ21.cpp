class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        unordered_map<int, bool> m;
        for(int i = 0; i < pushV.size(); ++i) {
            m.insert(pair<int, bool>(pushV[i], false));
        }
        int min_dex = 0;
        stack<int> store;
        for(int i = 0; i < popV.size(); ++i) {
            int popVal = popV[i];
            if(m.count(popVal) == 0)
                return false;
            else if(m[popVal] == false) {
                m[popVal] = true;
                for(int j = min_dex; j < pushV.size(); ++j) {
                    if(pushV[j] != popVal) {
                        store.push(pushV[j]);
                        m[pushV[j]] = true;
                    }
                    else {
                        min_dex = j + 1;
                        break;
                    }
                }
            }
            else {
                if(popVal == store.top()) {
                    store.pop();
                }
                else
                    return false;
            }
        }
        return true;
    }
};