//没有过多思考了 直接O(N)扫几遍解决了
int findJudge(int N, vector<vector<int>>& trust) {
        if(N==1) return 1;
        int arr[1001]={0};
        for(int i=0;i<trust.size();i++){
            arr[trust[i][0]]=1;
        }
        int tmp=0,idx=0;
        for(int i=1;i<=N;i++){
            if(arr[i]==0){
                tmp++;
                idx=i;
                //cout<<idx<<endl;
            }
        }
        if(tmp!=1) return -1;
        for(int i=0;i<trust.size();i++){
            if(trust[i][1]==idx)
                arr[trust[i][0]]=0;
        }
        for(int i=1;i<=N;i++){
                if(arr[i]==1)
                    return -1;
        }
        return idx;
    }
