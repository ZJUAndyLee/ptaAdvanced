//每个数组跟着一个hash表进行扩张按数组的每个位置的可能性进行扩张
class Solution {
public:
   vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<unordered_map<int,int>> hs;
	unordered_map<int, int> mp;
	vector<vector<int>> res(1, vector<int>());
	for (auto x : nums) {
		mp[x]++;
	}
	
	
	hs.push_back(mp);
	while (!hs.empty()) {
		vector<vector<int>> tmpres;
		vector<unordered_map<int, int>> tmphs;
		for (int i = 0; i < hs.size();i++) {
			if (hs[i].size() > 0) {
				unordered_map<int, int> tmpmp = hs[i];
				for (pair<int,int> p : hs[i]) {
					if (p.second > 0) {
						vector<int> tmpv = res[i];
						unordered_map<int, int> tmpmap = tmpmp;
						tmpv.push_back(p.first);
						tmpres.push_back(tmpv);
						tmpmap[p.first]--;
						if (tmpmap[p.first] == 0) {
							tmpmap.erase(p.first);
						}
						if (!tmpmap.empty())		
							tmphs.push_back(tmpmap);
					}
				}
			}
		}
		res = tmpres;
		hs = tmphs;
	}
	return res;
}
};
