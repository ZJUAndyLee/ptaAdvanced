//这个题我们采取的方法稍微不同 我们在建图的同时记录下每个顶点的入度的数量 从入度为0的顶点开始遍历 所有顶点按入度变成零的先后顺序进行排序
//也就是我们需要的拓扑路径

   vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses<1) return {};
        int *ind = new int[numCourses];
        for(int i=0;i<numCourses;i++){
            ind[i]=0;
        }
        unordered_map<int,unordered_set<int>> g;
        for(auto x:prerequisites){
            g[x.second].insert(x.first);
            ind[x.first]++;
        }
        queue<int> q;
        vector<int> res;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
            int tmp=q.front();
            q.pop();
            for(auto x:g[tmp]){
                ind[x]--;
                if(ind[x]==0){
                    q.push(x);
                    res.push_back(x);
                }
            }
        }
        for(int i=0;i<numCourses;i++){
            if(ind[i]!=0) return {};
        }
        return res;
    }
