//并查集做这个题很快

class Solution {
public:
    int findPar(int *p,int x){
        while(p[x]!=x){x=p[x];}
        return x;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int par[1001],sz=edges.size();
        pair<int,int> res;
        for(int i=0;i<1001;i++){
            par[i]=i;
        }
        for(int i=0;i<sz;i++){
            int p1=findPar(par,edges[i][0]);
            int p2=findPar(par,edges[i][1]);
            if(p1==p2){
                res.first=edges[i][0];
                res.second=edges[i][1];
            }
            else{
                par[p1]=p2;
            }
        }
        vector<int> vec={res.first,res.second};
        return vec;
    }
};
