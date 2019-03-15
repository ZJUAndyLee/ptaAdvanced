//找到超出限制的两个点 然后写了一个与n无关的算法 但是不知道为什么会超时。

class Solution {
public:
 void insidevec(vector<int> &vec,int num){
	stack<int> stk;
	while(vec.back()>num){
		stk.push(vec.back());
		vec.pop_back();
	}
	if(vec.back()<num) vec.push_back(num);
	while(!stk.empty()){
		vec.push_back(stk.top());
		stk.pop();
	}
}

int nthUglyNumber(int n) {
	vector<int> tmp={1};
	int ct=0,num;
	while(tmp.size()<=1690){
		num=tmp[ct];
		if(num<=424673280){
			insidevec(tmp,2*num);
			insidevec(tmp,3*num);
			insidevec(tmp,5*num);
		}	
		else if(num<=707788800){
			insidevec(tmp,2*num);
			insidevec(tmp,3*num);
		}
		else{
			insidevec(tmp,2*num);
		}
		ct++;
	}
	
	return tmp[n-1];
}
};
