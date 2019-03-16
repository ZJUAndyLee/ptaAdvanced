//本题最优算法的最差时间复杂度是一样的 但是最优时间复杂度可以优化
//我很无脑的建了一个最大堆然后进行 n的平方的操作
class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int> > > ,greater<pair<int, pair<int, int>>> > res;
		pair<int, pair<int, int>> tmp;
		vector<pair<int, int> > vec_p;
		for (int i = 0; i < nums1.size(); i++) {
			for (int j = 0; j < nums2.size(); j++) {
				pair<int, int> t_p(nums1[i], nums2[j]);
				tmp.second = t_p;
				tmp.first = nums1[i] + nums2[j];
				res.push(tmp);
			}
		}
		int ct = 0;
		while (!res.empty() && ct < k) {
			tmp = res.top();
			res.pop();
			vec_p.push_back(tmp.second);
			ct++;
		}
		return vec_p;
	}
};

//而在更优的算法里 需要计算的数对最大量其实不是和数组的大小挂钩 而是应该和k的大小挂钩
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       vector<pair<int,int>> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;//函数对象 在这里应用的时候不需要加括号 而在泛型算法里需要加上括号 应用的对象不同
        //在这里应该就是类的对象 而在泛型算法中应用的应该是类的函数
        for(int i = 0 ; i < min((int)nums1.size(),k);++i){//其实对于前k个最小的数对 肯定是在前k的平方数对中产生的
            for(int j = 0 ; j < min((int)nums2.size(),k);++j){
                if(q.size()<k){
                    q.push({nums1[i],nums2[j]});
                }else if(nums1[i]+nums2[j]<q.top().first+q.top().second){//这里是为了保证最大堆的最大值一定是k个数对中的最大值。
                    q.push({nums1[i],nums2[j]});
                    q.pop();
                }
            }
        }
        
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }
        return res;
            
        
    }
    
    struct cmp{
        bool operator()(pair<int,int> &a,pair<int,int> &b){
            return a.first+a.second<b.first+b.second;
        }
    };
};
