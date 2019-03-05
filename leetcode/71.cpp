//我的版本用时20ms 最大的缺点就是太在意/了 其实/只是一个标签我们只要判断/与/之间的元素就行了

class Solution {
public:
 string simplifyPath(string path) {
	vector<char> vec;
	int tmp = 0;
	for (int i = 0; i < path.size(); i++) {
		if (path[i] == '/') {
			if (vec.empty()) vec.push_back(path[i]);
			else if (vec.back() == '.' && tmp<3 ) {
				vec.pop_back();
				if (!vec.empty() && vec.back() == '.')
				{
					vec.pop_back();
					while (!vec.empty()) {
						vec.pop_back();
						if (vec.empty() || vec.back() == '/') break;
					}
				}
			}
			if (vec.empty() || vec.back() != '/') vec.push_back(path[i]);
			tmp = 0;
		}
		else if (path[i] == '.') { tmp++; vec.push_back(path[i]); }
		else vec.push_back(path[i]);
	}
	tmp = 0;
	for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == '.')
				tmp++;
	}
	if (tmp<3) {
		if (!vec.empty() && vec.back() == '.') {
			vec.pop_back();
			if (!vec.empty() && vec.back() == '.')
			{
				vec.pop_back();
				while (!vec.empty()) {
					vec.pop_back();
					if (vec.empty() || vec.back() == '/') break;
				}
			}
		}
	}
	if (vec.size() > 1 && vec.back() == '/') vec.pop_back();
	if (vec.empty()) vec.push_back('/');
	string ss;
	for (int i = 0; i < vec.size(); i++) ss.push_back(vec[i]);
	return ss;
}
};

//这是标准下8ms的版本 
class Solution {
public:
    string simplifyPath(string path) {
        string res, t;
        stringstream ss(path);//定义一个stringstream的类 将path给他初始化
        vector<string> v;
        while (getline(ss, t, '/')) {//调用函数 将path中每个/与/之间的字符串传给t 再分别处理不同的情况
            if (t == "" || t == ".") continue; 
            if (t == ".." && !v.empty()) v.pop_back();
            else if (t != "..") v.push_back(t);
        }
        for (string s : v) res += "/" + s;
        return res.empty() ? "/" : res;
    }
};
