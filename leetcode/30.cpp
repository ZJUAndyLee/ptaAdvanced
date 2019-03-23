//该题运用了一个基数排序的散列思想 根据关键字符串的第一个字符为关键字散列之后再用链表将其串接 麻烦的是字符串有可能重复 而且每次判断成功之后你不能进行跳跃。

class Solution {
public:
struct snode {
	string str;
	int times,ct;
	snode *next;
	snode(string tmp):str(tmp),times(1),next(NULL),ct(1){}
};

struct hasht {
	bool ex;
	snode *root;
	hasht():ex(0),root(NULL){}
};

vector<int> findSubstring(string s, vector<string>& words) {
	hasht *htable = new hasht[26];
	for (int i = 0; i < words.size(); i++) {
		int tmp = words[i][0] - 'a';
		if (!htable[tmp].root) {
			snode * sptr = new snode(words[i]);
			htable[tmp].root = sptr;
			htable[tmp].ex = 1;
		}
		else {
			snode *sptr = new snode(words[i]);
			snode *tmp_p = htable[tmp].root;
			while (tmp_p->next) {
				if (tmp_p->str == sptr->str) {
					tmp_p->times++;
					tmp_p->ct = tmp_p->times;
					break;
				}
				tmp_p = tmp_p->next; 
			}
			if(!tmp_p->next)tmp_p->next = sptr;
		}
	}
	int strSize = s.size(), vecSize = words.size();
	vector<int> res;
	if (!vecSize) return res;
	int wordSize = words[0].size(), j = 0;
	for (int i = 0; i < strSize; i++) {
		if (strSize - i >= vecSize * wordSize) {
			for (j = i; j < i+vecSize * wordSize; j += wordSize) {
				int tmp = s[j] - 'a';
				if (htable[tmp].ex) {
					string tmp_str = s.substr(j, wordSize);
					snode *sptr = htable[tmp].root;
					while (sptr) {
						//cout << sptr->str << " " << tmp_str << endl;
						if (sptr->times  && sptr->str == tmp_str) {
							sptr->times--;
							break;
						}
						sptr = sptr->next;
					}
					if (!sptr)  break; 
				}
				else break;
			}
			for (int k = 0; k < 26; k++) {
				if (htable[k].ex) {
					snode * tmp_ptr = htable[k].root;
					while (tmp_ptr) {
						tmp_ptr->times = tmp_ptr->ct;
						tmp_ptr = tmp_ptr->next;
					}
				}
			}
			if (j == i + vecSize * wordSize) {
				res.push_back(i); 
			} 
		}
	}
    return res;
}
};

