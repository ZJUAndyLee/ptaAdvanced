struct node {
	long long val;
	int iter;
	node *next;
	node(int v,int i):val(v),iter(i),next(NULL){}
};

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	if (k == 0) return false;
	node *root = NULL;
	for (int i = 0; i < nums.size(); i++) {
		if (!root) {
			node *ptr = new node(nums[i], i);
			root = ptr;
		}
		else {
			node *tmp = root;
			if (nums[i] < tmp->val) {
				node *ptr = new node(nums[i], i);
				ptr->next = root;
				root = ptr;
			}
			else {
				while (tmp->next) {
					if (nums[i] < tmp->next->val) {
						node *ptr = new node(nums[i], i);
						ptr->next = tmp->next;
						tmp->next = ptr;
						break;
					}
					tmp = tmp->next;
				}
				if (!tmp->next) {
					node *ptr = new node(nums[i], i);
					tmp->next = ptr;
				}
			}
		}
		if (i >= k) {
			if (i - k > 0) {
				int dlt = i - k - 1;
				node *tmp = root;
				if (tmp->iter == dlt) {
					root = root->next;
				}
				while (tmp->next) {
					if (tmp->next->iter == dlt) {
						tmp->next = tmp->next->next;
						break;
					}
					tmp = tmp->next;
				}
			}
			long long tmpMin = 9223372036854775807;
			node *tmp = root;
			while (tmp->next) {
				if (tmp->next->val - tmp->val < tmpMin) tmpMin = tmp->next->val - tmp->val;
				tmp = tmp->next;
			}
			if (tmpMin <= t) return true;
		}
	}
	node *tmpptr = root;
	while (tmpptr) {
		tmpptr = tmpptr->next;
	}
	if (k >= nums.size()) {
		long long tmpMin = 9223372036854775807;
		node *tmp = root;
		while (tmp->next) {
			if (tmp->next->val - tmp->val < tmpMin) tmpMin = tmp->next->val - tmp->val;
			tmp = tmp->next;
		}
		if (tmpMin <= t) return true;
	}
	return false;
}

//这个思路其实和求两数之和之类的题是一样的 一定要充分理解hash表的意义！！！
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long,int> m;
        int j=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i-j>k) m.erase(nums[j++]);
            auto a=m.lower_bound((long long)nums[i]-t);//这个点很难去思考到
            // 我们这样得到的一个key去map里找到一个不小于他的最近的一个数，而且这个数大于0，而如果比key的值更小的数的话就只会增大他们的差的绝对值
            
            if(a!=m.end()&&abs(a->first-nums[i])<=t) return true;
            m[nums[i]]=i;
        }
        return false;
    }
};
