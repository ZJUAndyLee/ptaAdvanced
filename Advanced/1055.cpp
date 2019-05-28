//用年龄做一个hash表 然后后面遍历年龄区间找到年龄合适的元素 再排序得到想要个数的结果 但是结果有一个点超时

#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct rich {
	string name;
	int worth, age;
	rich(string x, int y, int z) :name(x), age(y), worth(z) {  };
};
int num, qe;
vector<vector<rich>> hs;
vector<pair<int, pair<int, int>>> q;

bool cmp(rich &p1,rich &p2){
    if(p1.worth>p2.worth)
        return true;
    else if(p1.worth<p2.worth)
        return false;
    else {
        if(p1.age>p2.age)
            return false;
        else if(p1.age<p2.age)
            return true;
        else{
            if(p1.name>p2.name)
                return false;
            else
                return true;
        }
    }
}

void Input() {
	scanf("%d %d",&num,&qe);
	hs.assign(201, vector<rich>());
	for (int i = 0; i < num; i++) {
		char n[8];
		int age, worth;
		scanf("%s %d %d",&n,&age,&worth);
		hs[age].push_back(rich(n, age, worth));
	}
	for (int i = 0; i < qe; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		printf("Case #%d:\n", i + 1);
        vector<rich> res;
		for (int i = y; i <= z; i++) {
			for (auto y : hs[i]) {
				res.push_back(y);
			}
		}
        int idx = 1;
        sort(res.begin(),res.end(),cmp);
		for (auto z : res) {
			if (idx > x)
				break;
			printf("%s %d %d\n",z.name.c_str(),z.age,z.worth);
			idx++;
		}
		if (idx == 1)
            printf("None\n");
        res.clear();
	}

}


int main() {
	Input();
}
