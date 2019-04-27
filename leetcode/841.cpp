//这个题比较基础 直接建图加一个DFS就可以解决
class Solution {
public:
    vector<unordered_set<int>> g;
    vector<bool> v;
    void dfs(int root){
        v[root]=1;
        for(auto x:g[root]){
            if(!v[x]){
                dfs(x);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int sz=rooms.size();
        g.assign(1000,unordered_set<int>());
        for(int i=0;i<sz;i++){
            for(auto x:rooms[i]){
                g[i].insert(x);
            }
        }
        v.assign(1000,0);
        dfs(0);
        for(int i=0;i<sz;i++){
            if(!v[i]) return false;
        }
        return true;
    }
};
