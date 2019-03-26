//我的算法超时了 我觉得最大的问题就是每次对hash表的更新太费时了

string minWindow(string s, string t) {
	unordered_map<char, pair<int, int>> hash;
	for (int i = 0; i < t.size(); i++) {
		hash[t[i]].first++;
		hash[t[i]].second++;
	}
	int tmp = t.size(), ct = 0, len = 0, min = INT_MAX;
	string res = "";
	string strtmp="";
	if (s.size() >= t.size()) {
		for (int i = 0; i < s.size(); i++) {
			if (hash[s[i]].first) {
				int j = i;
				for (; j < s.size(); j++) {
					if (ct < tmp) {
						if (hash[s[j]].first) {
							hash[s[j]].first--;
							ct++;
							len++;
							strtmp.push_back(s[j]);
						}
						else {
							len++;
							strtmp.push_back(s[j]);
						}
					}
					else {
						if (len < min) {
							min = len;
							res = strtmp;
							//cout << res << " "<<i<<endl;
							strtmp = "";
							ct = 0; len = 0;
						}
						else {
							ct = 0; len = 0;
							strtmp = "";
						}
						break;
					}
				}
				if (j == s.size()) {
					if (ct == tmp) {
						if (len < min) {
							min = len;
							res = strtmp;
							strtmp = "";
							ct = 0; len = 0;
						}
						else {
							ct = 0; len = 0;
							strtmp = "";
						}
					}
					else break;
				}
				for (unordered_map<char, pair<int, int>>::iterator iter = hash.begin(); iter != hash.end(); iter++) {
					if (iter->second.second) iter->second.first = iter->second.second;
				}
			}
		}
	}
	return res;
}
