/**这个题就是我们平时所说的不相邻求最大值 方法也是动态规划 动态方程为：
    dp[i]=max(dp[i-2],dp[i-3])+w[i]
    最后结果的最大值为：max(dp[i],dp[i-1])**/
    
 //这个函数就是求数组不相邻的数的和的最大值
 int arrMax(vector<int> &vec,pair<int,int> p){
        if(p.first==p.second)
            return vec[p.first]*p.first;
        if(p.first==p.second-1)
            return max(vec[p.first]*p.first,vec[p.second]*p.second);
        if(p.first==p.second-2)
            return max(vec[p.first]*p.first+vec[p.second]*p.second,vec[p.first+1]*(p.first+1));
        vector<int> dp(p.second-p.first+1,0);
        dp[0]=vec[p.first]*p.first;
        dp[1]=max(vec[p.first]*p.first,vec[p.first+1]*(p.first+1));
        dp[2]=max(vec[p.first]*p.first+vec[p.first+2]*(p.first+2),vec[p.first+1]*(p.first+1));
        for(int i=3;i<=p.second-p.first;i++){
            dp[i]=max(dp[i-2],dp[i-3])+vec[p.first+i]*(p.first+i);
        }
        return max(dp[p.second - p.first], dp[p.second - p.first - 1]);
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> vec(10001,0);
        for(int x:nums){
            vec[x]++;
        }
        vector<pair<int,int>> tmpv;
        int st=1,ed=1;
        bool flag=true;
        //为了得到连续的子数组
        for(int i=1;i<10001;i++){
            if(flag){
                if(vec[i]!=0){
                    st=i;
                    flag=false;
                }
            }
            else{
                if(vec[i]==0){
                    ed=i-1;
                    tmpv.push_back(pair<int,int>(st,ed));
                    flag=true;
                }
            }
            
        }
        int res=0;
        for(auto p:tmpv){
            res+=arrMax(vec,p);
        }
        return res;
    }
