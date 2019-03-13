//这是我的一个很蠢的O(N平方)复杂度的算法 想用分治法实习发现分下去后其实很脏很难做 索性提交完之后看一下其他人的结果


int majorityElement(vector<int>& nums) {
	int tmp = nums[0], ct = 1, sz = nums.size();
	if (sz == 1||sz==2)return nums[0];
	for (int i = 0; i < sz / 2 + 1; i++) {
		ct = 1;
		for (int j = i + 1; j < sz; j++) {
			if (nums[i] == nums[j])ct++;
			if (ct > sz / 2) return nums[i];
		}
		if (nums[i + 1] == nums[i])i++;
	}
	return 0;
}

//范例算法很巧妙地运用了一个O(N)复杂度的算法 设置一个tmp如果在搜寻的过程中出现相同的 就记录次数+1，如果出现不同的情况就把次数减一 循环最开始的时候判断
//是否记录的次数为零 如果为零那么就把tmp赋值给当前循环的数 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0)
                cur = nums[i];
            if(nums[i] == cur)
                count++;
            else
                count--;
        }
        return cur;
    }
};
//这个算法的正确性不是显示的只能慢慢的去体会了
