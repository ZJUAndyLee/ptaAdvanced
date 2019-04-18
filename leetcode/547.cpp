//利用dfs非递归版本进行求解，得到想要的结果

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        bool hash[200]={false};
        int szM=M.size(),res=0;
        stack<int> stk;
        for(int i=0;i<szM;i++){
            if(!hash[i]){
                stk.push(i);
                while(!stk.empty()){
                    int k=stk.top();
                    stk.pop();
                    hash[k]=true;
                    for(int j=i+1;j<szM;j++){
                        if(M[k][j]==1&&!hash[j]){
                            stk.push(j);
                        }
                    }
                }
                res++;
            }
        }
        return res;
    }
};

//除此之外 我们还可以用并查集的方法的来求解 用一个数组来标记不同的数，而数组的里面的值就是该数的父结点

class Solution {
public:
    int findPar(int *par,int x){
        while(par[x]!=x){x=par[x];}
        return x;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int par[200];
        int szM=M.size(),res=0;
        for(int i=0;i<szM;i++){
            par[i]=i;
        }
        for(int i=0;i<szM;i++){
            for(int j=i;j<szM;j++){
                if(M[i][j]==1){
                    int x=findPar(par,i);
                    int y=findPar(par,j);
                    par[x]=y;
                }
            }
        }
        for(int i=0;i<szM;i++){
            if(par[i]==i) res++;
        }
        return res;
    }
};
