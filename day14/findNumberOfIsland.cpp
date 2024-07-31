void func(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid,int n,int m)
    {
        vis[i][j]=1;
       for(int s=-1;s<2;s++)
       {
           for(int t=-1;t<2;t++)
           {
               int x=i+s;
               int y=j+t;
               if( x<n && y<m && x>=0 && y>=0)
               {
                   if( grid[x][y]=='1' && vis[x][y]==0)
                   func(x,y,vis,grid,n,m);
               }
           }
       }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                   func(i,j,vis,grid,n,m);
                   ans++;
                }
            }
        }
        return ans;
    }