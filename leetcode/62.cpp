
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<=1&&n<=1) return 1;
        int path[101][101];
        for(int i=0;i<=m;i++){
            path[i][0]=0;
        }
        for(int j=1;j<=n;j++){
            path[0][j]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1&&j==1){
                    path[i][j]=1;
                }
                else{
                    path[i][j]=path[i-1][j]+path[i][j-1];
                }
            }
        }
        return path[m][n];
    }
};
