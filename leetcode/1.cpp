//这道题明显的哈希表的题 但是由于我对C++的标准库还是不是很熟悉 所以就没用想到用unordered_map去做

//unordered_map 其实内部的实现就是一个hash表 而map的内部实现是红黑树 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hash;
        
        for (int i = 0; i < nums.size(); i++) {
            auto iter = hash.find(target - nums[i]);//在找的过程中一个一个把hash表建完全而不是直接先建好再进行寻找
            if (iter != hash.end()) {
                return vector{iter->second, i};
            };
            hash[nums[i]] = i;
        }
        return vector<int>();
    }
};
