//这道题经历了很多个版本对于字符串处理散列查找总是比遍历要快的

//1.原始版本：图算法关键在于广度优先搜索的边的判断然后将每条边 依次进入队列想办法标记广度优先搜索的深度。最后用时900ms
class Solution {
public:
    
bool Adj(string &s1, string &s2) {
	int ct = 0;
	for (int i = 0; i<s1.size(); i++) {
		if (s1[i] != s2[i]) ct++;
	}

	return ct == 1 ? true : false;
}
int ladderLength(string bW, string eW, vector<string>& wordList) {
	int ct = 0, sz = wordList.size();
	for (; ct<sz; ct++) {
		if (wordList[ct] == eW) break;
	}
	if (ct == sz) return 0;
	queue<string> q;
	q.push(bW);
	string idx = bW;
	int res = 1, i = 1;
	while (!q.empty()) {
		string tmp = q.front();
		q.pop();
		if (idx == tmp||!i) {
			if (i) {
				res++;
				i = 0;
			}
			for (ct = 0; ct<wordList.size(); ct++) {
				if (Adj(wordList[ct], tmp)) {
					if (wordList[ct] == eW) {  return res; }
					if (!i) {
						idx = wordList[ct];
						i++;
					}
					q.push(wordList[ct]);
					wordList.erase(wordList.begin() + ct);
					ct--;
				}
			}
		}
		for (ct = 0; ct<wordList.size(); ct++) {
			if (Adj(wordList[ct], tmp)) {
				if (wordList[ct] == eW) return res;
				q.push(wordList[ct]);
				wordList.erase(wordList.begin() + ct);
				ct--;
			}
		}
	}
	return 0;
}
};

//第一次调整的版本双端搜索每次判断起点和终点的相同词的个数每次都从较小的一端往后搜索。
class Solution {
public:
    
bool Adj(string &s1, string &s2) {
	int ct = 0;
	for (int i = 0; i<s1.size(); i++) {
		if (s1[i] != s2[i]) ct++;
	}

	return ct == 1 ? true : false;
}
int ladderLength(string bW, string eW, vector<string>& wordList) {
    unordered_set<string> wdl(wordList.begin(),wordList.end());
	if(wdl.find(eW)==wdl.end()) return false;
	unordered_set<string> stSet;
    unordered_set<string> edSet;
	stSet.insert(bW);
    edSet.insert(eW);
	int res = 1;
	while (!stSet.empty()) {
		unordered_set<string> tmpSet;
        res++;
        for(auto x:stSet){
            wdl.erase(x); 
        } 
        for(auto x:stSet){
            for(auto y:wdl){
                if(Adj(x,y)){
                    if(edSet.find(y)!=edSet.end()) return res;
                    tmpSet.insert(y);
                }
            }
        }
        if(tmpSet.size()<edSet.size()){
            stSet=tmpSet;
        }
        else{
            stSet=edSet;
            edSet=tmpSet;
        }
	}
	return 0;
}
};
//最后一次调整 判断结点是否相连的方法的调整 我们遍历字符串中每个字符的可能取值 然后去字典里找找到了就判断它是不是在终点的集合里 是就返回否则就把它插入下一个起点或者终点
class Solution {
public:
    
bool Adj(string &s1, string &s2) {
	int ct = 0;
	for (int i = 0; i<s1.size(); i++) {
		if (s1[i] != s2[i]) ct++;
	}

	return ct == 1 ? true : false;
}
int ladderLength(string bW, string eW, vector<string>& wordList) {
    unordered_set<string> wdl(wordList.begin(),wordList.end());
	if(wdl.find(eW)==wdl.end()) return false;
	unordered_set<string> stSet;
    unordered_set<string> edSet;
	stSet.insert(bW);
    edSet.insert(eW);
	int res = 1;
	while (!stSet.empty()) {
		unordered_set<string> tmpSet;
        res++;
        for(auto x:stSet){
            wdl.erase(x); 
        } 
        for(auto x:stSet){
            for(int i=0;i<x.size();i++){
                string str=x;
                for(char c='a';c<='z';c++){
                    str[i]=c;
                    if(wdl.find(str)==wdl.end()) continue;
                    if(edSet.find(str)!=edSet.end()) return res;
                    tmpSet.insert(str);
                }
            }
        }
        if(tmpSet.size()<edSet.size()){
            stSet=tmpSet;
        }
        else{
            stSet=edSet;
            edSet=tmpSet;
        }
	}
	return 0;
}
};
