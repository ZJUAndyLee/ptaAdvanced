//跟着上题的思路用一个vector<vector<string>>来维护搜索路径用一个idx标记路径的长度然后每次遍历路径二维数组当数组的长度与idx相等的那个数组的最后一个值就是对应的当前结点
//知道遍历完毕 最后的路径数组满足两个条件的：1，长度与路径长度相同，2，路径的最后一个结点为终点的路径即为结果之一
class Solution {
public:
    vector<vector<string>> findLadders(string bW, string eW, vector<string>& wordList) {
    vector<vector<string>> res;
	unordered_set<string> wdl(wordList.begin(), wordList.end());
	if (wdl.find(eW) == wdl.end()) return res;
	vector<string> tmps;
	tmps.push_back(bW);
	res.push_back(tmps);
	unordered_set<string> stSet;
	stSet.insert(bW);
	int ct = 1, idx1 = 0, idx2 = 0, idx = 0;
	while (true) {
		unordered_set<string> tmpSet;
		idx1 = 0;
		for (auto x : res) {
			/*for (auto y : x) {
				cout << y << " ";
			}
			cout << endl;*/
			if (x.size() == ct) {
				wdl.erase(x[ct - 1]);
			}
		}
		int szRes = res.size();
		for (int i = 0; i < szRes; i++) {
			if (res[i].size() == ct) {
				idx = 0;
				int sz = res[i][ct - 1].size();
				for (int j = 0; j < sz; j++) {
					string str = res[i][ct - 1];
					for (char ch = 'a'; ch <= 'z'; ch++) {
						str[j] = ch;
						if (wdl.find(str) == wdl.end()) continue;
						idx++;
						if (idx == 1) {
							res[i].push_back(str);
						}
						else {
							vector<string> tmpS(res[i].begin(), res[i].end() - 1);
							tmpS.push_back(str);
							res.push_back(tmpS);
						}
						idx1 = 1;
						if (str == eW) idx2 = 1;
					}
				}
			}
		}
		ct++; 
		if (!idx1 || idx2) break;
	}

	vector<vector<string>> realres;
	if (!idx2) return realres;
	for (auto x : res) {
		if (x.size() == ct&&x.back()==eW) {
			realres.push_back(x);
		}
	}
	return realres;
    }
    };
//第一次优化
//每一次都遍历所有的长短不一的路径实在太傻 我们只需要遍历路径最长的路径 所以我们只需要维护一个与最长路径相同的数据结构即可而这个数据结构我们用
//unorderer_mp<string,vector<vector<string>>> map的第一个idx为当前结点 后面的二维数组表示起点到目前为止的路径的集合
//然后每当有新的路径生成我们都去找当前结点是否已经存在在的话就把当前的所有路径加上当前结点一起插入到map当中，否则就要以当前结点为idx重新生成pair
 vector<vector<string>> findLadders(string bW, string eW, vector<string>& wordList) {
	vector<vector<string>> res;
	unordered_set<string> wdl(wordList.begin(), wordList.end());
	if (wdl.find(eW) == wdl.end()) return res;
	vector<string> tmps;
	tmps.push_back(bW);
	res.push_back(tmps);
	unordered_map<string,vector<vector<string>>> resSet;
	resSet.insert(pair<string, vector<vector<string>>>(bW, res));
	int ct = 1, idx1 = 0, idx2 = 0;
	while (true) {
		//cout << resSet.size() << endl;
		unordered_map<string,vector<vector<string>>> tmpSet;
		idx1 = 0;
		for (auto x : resSet) {
			wdl.erase(x.first);
		}
		for (auto x:resSet) {
			int sz = x.first.size();
			for (int j = 0; j < sz; j++) {
				string str = x.first;
				for (char ch = 'a'; ch <= 'z'; ch++) {
					str[j] = ch;
					if (wdl.find(str) == wdl.end()) continue;
					idx1 = 1;
					vector<vector<string>> tmpvec = x.second;
					for (int i = 0; i < tmpvec.size();i++) {
						tmpvec[i].push_back(str);
					}
					if (tmpSet.find(str)==tmpSet.end()) {
						tmpSet.insert(pair<string, vector<vector<string>>>(str, tmpvec));
					}
					else{
						tmpSet[str].insert(tmpSet[str].end(), tmpvec.begin(), tmpvec.end());
					}
					if (str == eW) idx2 = 1;
				}
			}
		}
		ct++;
		resSet = tmpSet;
		
		if (!idx1 || idx2) break;
	}
	vector<vector<string>> realres;
	if (!idx2) return realres;
	for (auto x : resSet[eW]) {
		realres.push_back(x);
	}
	return realres;
}

//第二次优化：
//先用两头搜索以及 unordered_map<string, unordered_set<string>> 来构建一个图然后再深度优先搜索来把路径完善
class Solution {   
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
    	
    	unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord) == dict.end()) 
            return {};
        unordered_map<string, unordered_set<string>> nextNodeList;
        unordered_set<string> q[2] = {{beginWord},{endWord}};
        bool success = false;
        dict.erase(beginWord); 
        dict.erase(endWord);
        int cur = 0;
        while(!q[cur].empty() && !q[1-cur].empty())
        {
        	if(q[cur].size() > q[1-cur].size())
        		cur = 1-cur;
            unordered_set<string> nextLevel;
            for (auto item : q[cur])
            {
                for (int l = 0; l < item.size(); ++l) 
                {
                	auto next = item;
                    for (char c = 'a'; c <= 'z'; ++c)
                    {	
                        next[l] = c;
                        if(q[1-cur].find(next) != q[1-cur].end()) 
                        {
                            if(cur == 0) 
                            	nextNodeList[item].insert(next);
                            else 
                            	nextNodeList[next].insert(item);
                            success = true;
                        }
                        else if(dict.find(next) != dict.end())
                        {
                            nextLevel.insert(next);
                            if(cur == 0) 
                            	nextNodeList[item].insert(next);
                            else 
                            	nextNodeList[next].insert(item);
                        }
                    }
                }
            }
            if(success)
            	break;
            for(auto item : nextLevel)
                dict.erase(item); 
            q[cur] = nextLevel;
            cur = 1-cur;
        } 

        if(!success)
        	return {};
        vector<vector<string>> ret;
        vector<string> temp;
        temp.push_back(beginWord);
        dfs(nextNodeList,beginWord,endWord,ret,temp);        
        return ret;
    }

    void dfs(unordered_map<string, unordered_set<string>> &nextNodeList,string beginWord,string endWord,vector<vector<string>> &ret,vector<string> &temp)
    {
        if(beginWord == endWord)
        {
            ret.push_back(temp);
            return;
        }
        for(auto item : nextNodeList[beginWord]) 
        {
            temp.push_back(item);
            dfs(nextNodeList,item,endWord,ret,temp);
            temp.pop_back();
        }
    }
};
