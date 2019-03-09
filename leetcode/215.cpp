//利用冒泡排序进行前k个的排序再返回第k个
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int tmp;
		for (int i = 0; i < k; i++) {
			for (int j = i+1; j < nums.size(); j++) {
				if (nums[i] < nums[j]) { tmp = nums[j]; nums[j] = nums[i]; nums[i] = tmp; }
			}
		}
		return nums[k - 1];
	}
};

//更好的方法是先把任意的k个排好序然后再用剩下的与排好序中的最大值进行比较 如果大于就交换即可
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(!n)return 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < k; ++i)
            q.push(nums[i]);
        for(int i = k; i < n; ++i)
            if(nums[i] > q.top()){
                q.pop();
                q.push(nums[i]);
            }
        return q.top();
    }
};
