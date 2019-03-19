//建立最大堆找到最大间距 时间复杂度为O(Nlg(N))

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        priority_queue<int,vector<int>,greater<int>> minheap;//默认是大堆
        for(int i=0;i<nums.size();i++) minheap.push(nums[i]);
        int tmp=-1,ft=minheap.top();
        minheap.pop();
        while(!minheap.empty()){ 
            if(tmp<(minheap.top()-ft)){
                tmp=minheap.top()-ft;
                ft=minheap.top();
                minheap.pop();
            }
            else{
                ft=minheap.top();
                minheap.pop();
            }
        }
        return tmp;
    }
};

//线性时间复杂度的方法寻找最大间距
class Solution {
public:
    unsigned int getpos(int max,int min,int len,int num)
    {
        double a = num - min;
	    double b = max - min;
	
	    return (unsigned int)(a * len / b);
    }
    
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return 0;
        
        vector<bool> flag(len + 1,false);
        vector<int> maxs(len + 1,INT_MIN);
        vector<int> mins(len + 1,INT_MAX);
        int Max = INT_MIN;
        int Min = INT_MAX;
        
        for(int i=0;i<len;i++)
        {
            Min = min(nums[i],Min);
            Max = max(nums[i],Max);
        }
        
        if(Min == Max) return 0;
        
        flag[0] = true;
        flag[len] = true;
        
        for(int i=0;i<len;i++)
        {
            unsigned int pos = getpos(Max,Min,len,nums[i]);
            mins[pos] = min(mins[pos],nums[i]);
            maxs[pos] = max(maxs[pos],nums[i]);
            flag[pos] = true;
        }
        
        int res = INT_MIN;
        bool flag1 = false;
        int lastMax = maxs[0];
        for(int i=1;i<=len;i++)
        {
            if(flag[i])
            {
                res = max(res,mins[i] - lastMax);
                lastMax = maxs[i];
            }
        }
        
        return res;
    }
};
