//拓扑排序 在不输出的情况下判断是不是有环的算法 如下：
/*用散列表建图 dfs递归
两个数组st和ed分别表示顶点是否开始访问和顶点是否结束访问
当我们在访问邻接顶点时 如果出现了某个顶点开始访问了却没有结束访问说明成环。*/
class Solution {
public:
    bool dfs(unordered_map<int, unordered_set<int>>&g,int *st,int *ed,int x){
        st[x]=1; 
        for(auto y : g[x]){
            if(st[y]&&!ed[y]) return false;
            if(!st[y])  {if(!dfs(g,st,ed,y)) return false;};
        }
        ed[x]=1;
        return true;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	if (numCourses<1) return true;
	int *st = new int[numCourses];
    int *ed = new int[numCourses];
	for (int i = 0; i<numCourses; i++) {
		st[i] = 0;
        ed[i] = 0;
	}
	unordered_map<int, unordered_set<int>> g;
	for (auto x : prerequisites) {
		g[x.second].insert(x.first);
	}
	for(int i=0;i<numCourses;i++){
        if(!st[i]){
            if(!dfs(g,st,ed,i)){
                return false;
            };
        }
    }
	return true;
}
};
