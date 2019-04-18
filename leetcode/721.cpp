//重新审视并查集的步骤与方法
//1，每个结点都建立一个独立的集合 也即父结点是自己的集合
//2，对于不同的集合可以用集合中的某一个元素也可以用一个标签表示集合的代表，然后把已经得到的集合建立起来 也即把现成集合的所有元素的父结点统一
//3，然后再对所有的元素进行合并，合到同一个集合里面。
string findPar(unordered_map<string, string>&p, string str) {
	while (p[str] != str) { str = p[str]; }
	return str;
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
	unordered_map<string, string> par;
	unordered_map<string, string>name;
	unordered_map<string, set<string>> uniSet;

	for (int i = 0; i < accounts.size(); i++) {
		for (int j = 1; j < accounts[i].size(); j++) {
			name[accounts[i][j]] = accounts[i][0];
			par[accounts[i][j]] = accounts[i][j];
		}
	}
	for (int i = 0; i < accounts.size(); i++) {
		string p = findPar(par, accounts[i][1]);
		for (int j = 2; j < accounts[i].size(); j++) {
			par[findPar(par, accounts[i][j])] = p;
		}
	}
	for (int i = 0; i < accounts.size(); i++) {
		for (int j = 1; j < accounts[i].size(); j++) {
			uniSet[findPar(par, accounts[i][j])].insert(accounts[i][j]);
		}
	}
	vector<vector<string>> res;
	for (auto x : uniSet) {
		vector<string> tmpStr;
		tmpStr.push_back(name[x.first]);
		tmpStr.insert(tmpStr.end(), x.second.begin(), x.second.end());
		res.push_back(tmpStr);
	}
	return res;
}
