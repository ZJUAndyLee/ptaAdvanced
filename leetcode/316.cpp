//这是少有的完全没有想法的题目整体思路在于记录出现的次数以及标记是否为正确的位置 虽然我的算法是最快的 但是整体思路并不是很清晰

string removeDuplicateLetters(string s) {
	int times[26] = { 0 };//times数组标记出现的次数
	bool plcJge[26] = { false }; //plc数组标记每个字母是否已经位于正确的位置上
	string res = "";
	int sz = s.size();
	for (int i = 0; i < sz; i++) {
		times[s[i] - 'a']++;//遍历一遍 把每个字母的出现的次数得到
	}
	for (int i = 0; i < sz; i++) {
		times[s[i] - 'a']--;//每个字母出现就把他出现的次数减一
		if (res.size() == 0) {  //res为结果字符串 如果该字符串为空 那么就直接把字符 push进入字符串
			res.push_back(s[i]);
			//chEx[s[i] - 'a'] = true;
		}
		else {
			if (res.find(s[i]) == string::npos) {//首先寻找当前字符是否在结果字符串中 在的话我们不需要进行下面的判断
				while (!res.empty() && !plcJge[res.back() - 'a']) { //首先当我们的字符串不为空而且字符串最后一个字符不在正确的位置上的话
					if (times[res.back() - 'a'] && res.back() > s[i]) {//我们判断当字符串最后一个字符以后出现的次数不为零 而且他的字典序大于当前字符
						res.pop_back();//我们把它抛出
					}
					else if (times[res.back() - 'a'] == 0) {//否则如果最后一个字符以后出现的次数为零 那么就说明最后一个字符在正确位置上了
						for (int j = 0; j < res.size(); j++) {//而且由于res都是按递增顺序所以前面的字符也就都在自己的正确的位置上了
							plcJge[res[j] - 'a'] = true;
						}
						break;
					}
					else {//如果最后一个字符以后出现的次数不为零而且字典序比当前字符小那么直接跳出循环
						break;
					}
				}
				if (res.empty() || (res.back() != s[i] && !plcJge[s[i] - 'a'])) {//跳出循环之后我们要判断 如果res为空或者res的最后一个字符不重复且当前字符不在正确的位置上那么直接push进res即可。
					res.push_back(s[i]);
				}
			}
		}
	}
	return res;
}
