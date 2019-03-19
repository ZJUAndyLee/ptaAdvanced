//最直接的思路 基数排序 把规则搞清楚 这里最复杂的就是字符串比大小的规则需要反复比较有些麻烦 代码量很大而且不易读 虽然整个时间复杂度还可以 但是整体效率不高

struct snode {
	string str;
	snode *next;
	snode(){}
	snode(string s):str(s),next(NULL){}
};

bool cmp(string str1,string str2) {
	int s1 = str1.size(), s2 = str2.size();
	if (s1 < s2) {
		if(str2.compare(0, s1, str1)<0) return true;
		else if (str2.compare(0, s1, str1) == 0) {
			int ct = 1; string tmp;
			while (true) {
				tmp = str2.substr(ct*s1, s1); ct++;
				if (tmp != str1) break;
				
			}
			if(str1.compare(0, tmp.size(), tmp)>0||tmp=="") return true;
			else if(str1.compare(0, tmp.size(), tmp)==0){
				int ct1 = 1; string tmp1;
				while (true) {
					tmp1 = str1.substr(ct1*tmp.size(), tmp.size()); ct1++;
					if (tmp1 != tmp) break;
				}
				if(tmp.compare(0,tmp1.size(),tmp1)<0) return true;
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else if (s1 == s2) {
		if (str1.compare(0, s2, str2) > 0) return true;
		else return false;
	}
	else {
		if (str1.compare(0, s2, str2) > 0) return true;
		else if (str1.compare(0, s2, str2) == 0) {
			int ct = 1; string tmp;
			while (true) {
				tmp = str1.substr(ct*s2, s2); ct++;
				if (tmp != str2) break;
			}
			if (str2.compare(0, tmp.size(), tmp) < 0||tmp=="")return true;
			else if(str2.compare(0, tmp.size(), tmp)==0){
				int ct1=1;string tmp1;
				while (true) {
					tmp1 = str2.substr(ct1*tmp.size(), tmp.size()); ct1++;
					if (tmp1 != tmp) break;
				}
				if(tmp.compare(0,tmp1.size(),tmp1)>0) return true;
				else return false;
			}
			else return false;
		}
		else return false;
	}
}

void s_insert(snode *root,string val) {
	if (!root->next) {
		snode *ptr = new snode(val);
		root->next = ptr;
	}
	else {
		snode *tmp = root->next;
		if (cmp(val, tmp->str)) {
			snode *ptr = new snode(val);
			ptr->next = root->next;
			root->next = ptr;
		}
		else {
			while (tmp->next) {
				if (!cmp(val, tmp->next->str)) tmp = tmp->next;
				else {
					snode *ptr = new snode(val);
					ptr->next = tmp->next;
					tmp->next = ptr;
					break;
				}
			}
			if(!tmp->next){ snode *ptr = new snode(val); tmp->next = ptr;}
		}
	}
}

string largestNumber(vector<int>& nums) {
	snode *s_arr = new snode[10];
	string tmp;
	string res = "";
	for (int i = 0; i < 10; i++) {
		s_arr[i].str = to_string(i);
		s_arr[i].next = NULL;
	}
	for (int i = 0; i < nums.size(); i++) {
		tmp = to_string(nums[i]);
		switch (tmp[0])
		{
		case '9':
			s_insert(s_arr + 9, tmp);
			break;
		case '8':
			s_insert(s_arr + 8, tmp);
			break;
		case '7':
			s_insert(s_arr + 7, tmp);
			break;
		case '6':
			s_insert(s_arr + 6, tmp);
			break;
		case '5':
			s_insert(s_arr + 5, tmp);
			break;
		case '4':
			s_insert(s_arr + 4, tmp);
			break;
		case '3':
			s_insert(s_arr + 3, tmp);
			break;
		case '2':
			s_insert(s_arr + 2, tmp);
			break;
		case '1':
			s_insert(s_arr + 1, tmp);
			break;
		default:
			s_insert(s_arr , tmp);
			break;
		}
		
	}
	for (int i = 9; i >= 0; i--) {
		snode *ptr = s_arr[i].next;
		while (ptr) {
			res += ptr->str;
			ptr = ptr->next;
		}
	}
	if(res.size()>0){
		if(res[0]=='0') return "0";
	}
	return res;
}
