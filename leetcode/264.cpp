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

//一个超级好的算法 堪称O(1)时间复杂度
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        int idx2=0, idx3=0, idx5=0;//分别给2，3，5三个数一个指标
        vector<int> Uset(n);
        Uset[0]=1;
        for(int i=1; i<n; ++i)
        {
            Uset[i]=min(min(Uset[idx2]*2,Uset[idx3]*3),Uset[idx5]*5);//因为丑数都是丑数演化的所以每个丑数乘以2，3，5都有机会成为下一个丑数
//所以每次都是得出三种演化中最小的一个数 进入数组，然后分别去判断这个最小的数是通过哪一种方式演化得到的
	    //找出该演化方式然后往后进一位，简直完美。
            if(Uset[i]==Uset[idx2]*2) ++idx2;
            if(Uset[i]==Uset[idx3]*3) ++idx3;
            if(Uset[i]==Uset[idx5]*5) ++idx5;
        }
        return Uset[n-1];

    }
};
