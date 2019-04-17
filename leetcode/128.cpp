//这个题我严格按照了并查集以及启发式策略按秩归并路径压缩 hash数组然后查找相邻的数 存在就把他们归并

class Solution {
public:
   struct uniSet {
	int val;
	uniSet *root;
	uniSet() :val(0), root(NULL) {}
	uniSet(int num, uniSet *p) :val(num), root(p) {}
};
uniSet * ysPath(uniSet *ptr, uniSet *r) {
	if (ptr == ptr->root) {
        ptr->root = r;
		return r;
	}
	else ptr->root = ysPath(ptr->root, r);
	return r;
}
int longestConsecutive(vector<int>& nums) {
	unordered_map<int, uniSet *> hash;
	int res = 0;
	for (int i = 0; i<nums.size(); i++) {
		if (hash[nums[i]]) { 
			continue; 
		}
		hash[nums[i]] = new uniSet(1, NULL);
		hash[nums[i]]->root = hash[nums[i]];
		if (hash[nums[i] - 1]) {
			uniSet * tmp = hash[nums[i] - 1]->root;
			if (tmp != hash[nums[i] - 1]) {
				while (tmp != tmp->root) {
					tmp = tmp->root;
				}
			}
			hash[nums[i]]->root = tmp;
			tmp->val++;
		}
		if (hash[nums[i] + 1]) {
			uniSet * tmp = hash[nums[i] + 1]->root;
			if (tmp != hash[nums[i] + 1]) {
				while (tmp != tmp->root) {
					tmp = tmp->root;
				}
			}
			if (tmp->val> hash[nums[i]]->root->val) {
				tmp->val += hash[nums[i]]->root->val;
				hash[nums[i]]->root = ysPath(hash[nums[i]], tmp);
			}
			else {
				hash[nums[i] + 1]->root = ysPath(hash[nums[i] + 1], hash[nums[i]]->root);
				hash[nums[i]]->root->val += tmp->val;
			}
		}
		if (res<hash[nums[i]]->root->val) {
			res = hash[nums[i]]->root->val;
			//cout << res<<endl;
		}
	}
	return res;
}
};

//英文版高赞回答 先将整个数组hash然后再遍历数组对于每一个数直接erase然后两头分别按++和--去查找直到找不到为止然后查找的区间也就为最大连续序列的区间
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> record(num.begin(),num.end());
        int res = 1;
        for(int n : num){
            if(record.find(n)==record.end()) continue;
            record.erase(n);
            int prev = n-1,next = n+1;
            while(record.find(prev)!=record.end()) record.erase(prev--);
            while(record.find(next)!=record.end()) record.erase(next++);
            res = max(res,next-prev-1);
        }
        return res;
    }
};
