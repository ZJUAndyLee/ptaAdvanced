//我的算法是建立最小堆以及用二分查找的方式找到每次需要进入结果数组的元素 其实这两步的时间复杂度均为lg(k)但是估计是最后判断重复的地方花了太多的时间了
pair<int, int> findp(vector<pair<int,int>> &vec,int prime) {
	int max = vec.size(),min=0;
	int tmp; 
	while (true) {
		tmp = (max + min) / 2;
		if (vec[tmp].first > prime) max = tmp;
		else if (vec[tmp].first < prime) min = tmp;
		else { vec[tmp].second++; break; }
		
	}
	return vec[tmp];
}

int nthSuperUglyNumber(int n, vector<int>& primes) {
	if (n == 1) return 1;
	vector<int> res = { 1 };
	vector<pair<int, int>> idx;
	int p_sz = primes.size();
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
	for (int i = 0; i < p_sz; i++) idx.push_back(pair<int, int>(primes[i], 0));//(prime,index)
	for (int j = 0; j < p_sz; j++) {
		minheap.push(pair<int, int>(res[idx[j].second] * idx[j].first,idx[j].first));
	}
	//(value,prime)
	
	for (int i = 1; i < n; i++) {
		pair<int, int> tmp = minheap.top();
		int val = tmp.first;
		res.push_back(val);
		while (tmp.first == val) {
			minheap.pop();
			tmp = findp(idx, tmp.second);
			
			minheap.push(pair<int, int>(res[tmp.second] * tmp.first, tmp.first));
			tmp = minheap.top();
		}
	}
	return res[n - 1];
}


//较优算法就是直接为每个prime建立一个index这样的话最后直接遍历整个prime index数组寻找到需要增加的index
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> d(m,0),res(1,1);
        for(int i = 1;i<n;++i){
            int temp = INT_MAX;
            for(int j = 0;j<m;++j){
                temp = min(temp,primes[j]*res[d[j]]);
            }
            res.push_back(temp);
            for(int j = 0;j<m;++j){
                if(temp == primes[j]*res[d[j]]) ++d[j];
            }
        }
        return res[n-1];
    }
};
