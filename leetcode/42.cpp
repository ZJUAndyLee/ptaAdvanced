class Solution {
public:
   
int trap(vector<int>& height) {
	queue<int> que;
	int tmp, tt = 0;
	for (vector<int>::iterator i = height.begin(); i != height.end(); i++) {//通过迭代器进行遍历vector 可以更好的利用后面的泛型算法
		
		if (que.empty()) que.push(*i);
		if (que.size() == 1) {
			if (*i >= que.front()) {//判断是否队列里的第一个元素小于第二个 如果是就让第一个出队
				que.pop();
				que.push(*i);
			}
			else que.push(*i);
		}
		else {
			if (*i >= que.front()) {
				tmp = que.front();
				while (!que.empty()) {
					tt += (tmp - que.front());
					que.pop();
				}
				que.push(*i);
			}
			else if (*i > *(i - 1)) {
				if (i == max_element(i, height.end())) {算法耗时关键！！需要判断当前元素是否为后面元素中的最大值 需要一直判断有待改进
					tmp = *i;
					que.pop();
					while (!que.empty()) {
						if(tmp>que.front()) tt += (tmp - que.front());
						que.pop();
					}
					que.push(*i);
				}
				else que.push(*i);
			}
			else que.push(*i);
		}
	}
	return tt;
}
};


//样例最漂亮的是一个8ms版本的算法

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
    	int l = 0;
        int r = height.size() - 1;
    	int lmax = 0;
        int rmax= 0;
    	while (l < r) {//从左右同时向中间出发进行遍历
    		lmax = lmax > height.at(l) ? lmax : height.at(l);//把左边的最大值赋值给lmax
    		rmax = rmax > height.at(r) ? rmax : height.at(r);//把右边的最大值赋值给rmax
    		if (lmax < rmax) {//判断左右两边的最大值的大小 然后在前进遍历的过程中把较小最大值与当前附近的元素相减 然后再累加得到结果！！！
    			res += lmax - height[l];
    			++l;
    		}else{
    			res += rmax - height[r];
    			--r;
    		}
    	}
    	return res;
    }
};
