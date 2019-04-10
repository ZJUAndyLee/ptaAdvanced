//分发糖果 主要思路就是遍历整个ratings数组 数组里面有递增和递减的趋势 在不减序列的最后一个将他标记为峰值 三种判断如果它是严格递增那么就必须糖果数也递增
//而如果是相等就把目前的糖果数设为1 如果是严格递减那么必须有一个count来记录递减的序列的数目 如果数目大于等于峰值的糖果数那么就必须当前直到峰值都需要
//加上一颗糖 否则就只需要从当前到峰值前面加上一颗糖即可


class Solution {
public:
   int candy(vector<int>& ratings) {
	int sz = ratings.size();
	if (sz < 1) return 0;
	if (sz < 2) return 1;
	int peak = 0, res = 0, tmp = 0, ct = 0, numPeak = 0;
	for (int i = 0; i < sz; i++) {
		if (i == 0) {
			if (ratings[i + 1] == ratings[i]) {
				tmp = 1;
				res += tmp;
			}
			else if (ratings[i + 1] < ratings[i]) {
				tmp = 2;
				res += tmp;
			}
			else {
				tmp = 1;
				res += tmp;
				peak = i + 1;
			}
		}
		else {
			if (ratings[i] == ratings[i - 1]) {
				tmp = 1;
				res += tmp;
				peak = i;
				numPeak = tmp;
				ct = 0;
			}
			else if (ratings[i - 1] < ratings[i]) {
				tmp++;
				res += tmp;
				peak = i;
				numPeak = tmp;
				ct = 0;
			}
			else {
				ct++;
				if (tmp>1) {
					tmp = 1;
					res += tmp;
				}
				else {
					if (ct < numPeak) {
						res += i - peak;
						tmp = 1;
					}
					else {
						res += i - peak + 1;
						tmp = 1;
					}
				}
			}
		}
		//cout << res <<" "  <<peak<<endl;
	}
	return res;
}
};

//另一个更好的思路 首先所有的孩子必须有一颗糖
//第一遍遍历是正向遍历 如果序列严格递增那么当前糖果数就等于前面一个孩子的糖果数+1
//然后反向遍历 如果是严格递增 而且当前孩子的糖果数小于等于前一个小孩的糖果就等于前一个小孩糖果数+1

class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n=ratings.size();
        if(n==0) return 0;
        vector<int> candies(n,1);
        for(int i=0;i<n-1;++i)
        {
            if(ratings[i+1]>ratings[i])
                candies[i+1]=candies[i]+1;
        }
        int res=0;
        for(int i=n-1;i>=1;--i)
        {
            if(ratings[i-1]>ratings[i]&&candies[i-1]<=candies[i])
                candies[i-1]=candies[i]+1;
            res+=candies[i];
        }
        res+=candies[0];
        return res;
    }
};
