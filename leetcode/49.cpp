//前面被我注解的方法是利用 三次方进行散列 后面投机取巧的方法直接对字符串进行排序排序之后的字符串作为关键词，思路挺不错的

class Solution {
public:
   /*vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<int, vector<string>> hashing;
	unordered_map<int, int> tmp_hashing;
	vector<vector<string>> res;
	for (int i = 0; i < strs.size(); i++) {
		int idx = 0;
		for (int j = 0; j < strs[i].size(); j++) {
			idx += pow(strs[i][j]-'a',3);
		}
		if (!tmp_hashing[idx]) {
			tmp_hashing[idx] = 1;
			vector<string> str;
			str.push_back(strs[i]);
			hashing[idx] = str;
		}
		else {
            while(tmp_hashing[idx]){
                unordered_map<char,int> tmp1;
                unordered_map<char,int> tmp2;
                for(int j=0;j<hashing[idx][0].size();j++) tmp1[hashing[idx][0][j]]++;
                for(int j=0;j<strs[i].size();j++) tmp2[strs[i][j]]++;
                int k=0;
                for(k=0;k<hashing[idx][0].size();k++){
                    if(tmp1[hashing[idx][0][k]]!=tmp2[hashing[idx][0][k]]) break;
                }
                if(k==hashing[idx][0].size()) {
                    hashing[idx].push_back(strs[i]);
                    break;
                }
                else idx++;
            }
            if(!tmp_hashing[idx]){
                tmp_hashing[idx] = 1;
			    vector<string> str;
			    str.push_back(strs[i]);
			    hashing[idx] = str;
            }
        }
	}
	for (unordered_map<int, int>::iterator iter=tmp_hashing.begin(); iter != tmp_hashing.end(); iter++) {
        //cout<<(*iter).second<<" "<<(*iter).first<<endl;
		if ((*iter).second) {
			res.push_back(hashing[(*iter).first]);
		}
	}
	return res;
}*/
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        map<string,vector<string>> hashing;
        vector<vector<string>> res;
        for(int i=0;i<strs.size();i++){
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            hashing[tmp].push_back(strs[i]);
        }
        for(map<string,vector<string>>::iterator iter=hashing.begin();iter!=hashing.end();iter++){
            res.push_back((*iter).second);
        }
        return res;
    }
};
