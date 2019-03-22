//这是第一道我连测试案例都没过的题 我觉得做这个题还是不能太去追求算法效率首先要把能做的先快速做出来了 给自己定一个时间段 如果做题的时间超过两个小时就
//看提示 或者直接看前面的算法吧

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < int(nums.size() - 3); ++i) {//把四数之和转化为三数
            for (int j = i + 1; j < int(nums.size() - 2); ++j) {//把三数之和再转化为两数
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;//因为前面是有序的啦 所以相邻的相等的要直接排除掉
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {//两数求和找目标
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};//用一个set也是为了保证里面的vector<>不重复
                        res.insert(out);
                        ++left; --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
