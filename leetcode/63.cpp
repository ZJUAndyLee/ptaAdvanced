class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        long long path[101][101];
        if(obstacleGrid.size()<1)return 0;
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        for(int i=0;i<=m;i++){
            path[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            path[0][i]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){  
                if(obstacleGrid[i-1][j-1]){
                        path[i][j]=0;
                } 
                else{
                    if(i==1&&j==1){
                        path[i][j]=1;
                    }
                    else{
                        path[i][j]=path[i-1][j]+path[i][j-1];
                    }
                }
            }
        }
    
        return path[m][n];
    }
};
