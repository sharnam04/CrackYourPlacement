class Solution {
private:
void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis)
{
    int n=grid.size();
    int m=grid[0].size();
    vis[row][col]=1;
    int dirx[]={0,1,0,-1};
    int diry[]={1,0,-1,0};
    for(int i=0;i<4;i++)
    {
        int row2=row+dirx[i];
        int col2=col+diry[i];
        if(row2>=0 && col2>=0 && row2<n && col2<m)
        {
            if(!vis[row2][col2] && grid[row2][col2]=='1')
            {
                dfs(row2,col2,grid,vis);
            }
        }
    }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};