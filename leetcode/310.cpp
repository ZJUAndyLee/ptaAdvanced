//这个题主要是要找到解题思路，思路对了其实就很简单了 我们要把所有的度为1的结点依次剪掉直到只剩一个或者两个结点相当于一个从外往里的BFS而关键的一个对列的使用能够使
//时间复杂度降到O(N)
//越边缘的点他的树的高度越高 越中心的点树高度也就越低 这就是这个题的中心思想
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
	vector<int> res;
    if(edges.size()<1){//边界情况
        res.push_back(0);
        return res;
    }
	vector<unordered_set<int>> g(n,unordered_set<int>());
	for (auto &x : edges) {//建图
		g[x[0]].insert(x[1]);
		g[x[1]].insert(x[0]);
	}
    queue<int> q;
    for(int i=0;i<n;i++){//首先把最开始度为1的点进入队列
        if(g[i].size()==1)
            q.push(i);
    }
	int sum = n;
	while (sum > 2) {//使结点和始终保持大于2的水平
       int sz=q.size();//记录下每一轮q的size因为我们q是动态的所以必须记录下刚进入循环的size的大小
        sum-=sz;
        for(int i=0;i<sz;i++){
            int tmp=q.front();
            q.pop();
            for(auto x:g[tmp]){//对于度为1的结点我们从与他相连的结点中把他删了
                g[x].erase(tmp);
                if(g[x].size()==1) q.push(x);//如果删掉之后度变成了1那么就入队 这就是下一轮度为1的结点
            }
        }
	}

	while(!q.empty()){
        res.push_back(q.front());
        q.pop();
    }
	return res;
}
};

