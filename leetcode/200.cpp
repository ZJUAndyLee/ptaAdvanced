//一个典型的dfs求解的方法
class Solution {
public:
    void dfs(vector<vector<char>> &grid,int row,int col){
        int szrow=grid.size(),szcol=grid[0].size();
        if(row<0||row>=szrow||col<0||col>=szcol||grid[row][col]=='0') return;
        grid[row][col]='0';
        dfs(grid,row-1,col);
        dfs(grid,row+1,col);
        dfs(grid,row,col-1);
        dfs(grid,row,col+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()<1) return 0;
        int row=grid.size(),col=grid[0].size(),res=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};
