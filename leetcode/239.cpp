//该算法是一个分治法 通过分治法 递归求得滑动窗口的最大值
class Solution {
public:
   int findmax(vector<int> &vec,int st,int ed){
	int sz=ed-st+1;
	if(sz==1) return vec[st];
	if(sz==2) return vec[st]>vec[ed]?vec[st]:vec[ed];
	int mid=(st+ed)/2;
	int l_max,r_max;
	l_max=findmax(vec,st,mid);
	r_max=findmax(vec,mid+1,ed);
    return l_max>r_max?l_max:r_max;
}
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> res;
	int tmp;
	for(int i=0;i+k-1<nums.size();i++){
		tmp=findmax(nums,i,i+k-1);
		res.push_back(tmp);
	}
	return res;
}
};

//动态规划算法用一个时间复杂度为O(N)的方法得到了结果 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size() <= 0 || k <= 0 || nums.size() < k) //这个是没有最大值的结果
            return ans;
        deque<int> q;
        for(int i=0; i<nums.size(); i++){
            if(q.empty()) q.push_back(i);
            else{
                while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();//把进来的数的句柄存入队列当中 每次新来的数如果大于前面的数就把前面的数给pop出来
                q.push_back(i);//然后将该数push进入队伍 这个过程能够使队列中的最大数永远在队列的最上面
            }
            if(i >= k - 1){//当i大于k-1的时候就说明需要开始进行最大数的计算了 
                while(!q.empty() && q.front() < i - k + 1) q.pop_front();//这个过程是为了把滑动窗口过了的数全部出队
                ans.push_back(nums[q.front()]);//这样的话就可以每次都把窗口里的最大数轻松得到
            }
        }
        return ans;
    }
};
