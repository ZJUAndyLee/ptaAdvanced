  void Ctchar(string &s,vector<int> &vec) {
	for (char c : s) {
		vec[c - 'a']++;
	}
}

vector<string> commonChars(vector<string>& A) {
	vector<int> res(26,0);
	for (int i = 0; i < A.size(); i++) {
		vector<int> tmpv(26, 0);
		if (i == 0) {
			Ctchar(A[i], res);
		}
		else {
			Ctchar(A[i], tmpv);
			for (int i = 0; i < 26; i++) {
				res[i] = min(res[i], tmpv[i]);
			}
		}
	}
	vector<string> ans;
	for (int i = 0; i < 26; i++) {
		if (res[i] > 0) {
			for (int j = 0; j < res[i]; j++) {
				ans.push_back(string(1, 'a' + i));
			}
		}
	}
	return ans;
}
