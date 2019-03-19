//我自己的算法去对每个字母进行排序是在有些傻了
bool isAnagram(string s, string t) {
	vector<char> str1;
	vector<char> str2;
	if (s.size() != t.size())return false;
	for (int i = 0; i < s.size(); i++) {
		str1.push_back(s[i]);
	}
	for (int i = 0; i < t.size(); i++) {
		str2.push_back(t[i]);
	}
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	int j = 0;
	for (j = 0; j < str1.size(); j++) {
		if (str1[j] != str2[j]) break;
	}
	if (j < str1.size())return false;
	return true;
}
//很简单 只需要记录下每个字母的个数 如果有某个字母的个数不同那么就说明 不相等
效的字母异位词
提交记录
34 / 34 个通过测试用例
状态：通过
执行用时：68 ms
提交时间：0 分钟之前
执行用时分布图表
0204060801001201405101520253035
cpp
我的提交执行用时
已经战胜 2.72 % 的 cpp 提交记录
Runtime (ms)Distribution (%)

020406080100120140102030
在此图表上拖选来放大显示该区域

邀请好友来挑战 有效的字母异位词
提交的代码：0 分钟之前
语言：cpp

返回该题
× 关闭
执行用时为 8 ms 的范例
static const auto io_sync_off = []()
{
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	std::cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public: 
    bool isAnagram(std::string s, std::string t) {
        int sArray[26] = {0}, tArray[26] = {0}, i = 0;
        int sLen = s.length(), tLen = t.length();
        if(sLen != tLen)
            return 0;
        while(i < sLen) {
            sArray[s[i] - 'a']++;
            tArray[t[i++] - 'a']++; 
        }
        i = 0;
        while(i < 26) {
            if(sArray[i] != tArray[i])
                return 0;
            i++;
        }
        return 1;
    }
};
