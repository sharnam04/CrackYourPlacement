int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<pair<int,int>,int>>q;
        int dirx[]={0,-1,0,1};
        int diry[]={-1,0,1,0};
        
        vector<vector<int>>vis=grid;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                }
            }
        }
        int ans=0;
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int xnew=x+dirx[i];
                int ynew=y+diry[i];
                if(xnew>=0 && xnew<row && ynew>=0 && ynew<col)
                {
                    if(vis[xnew][ynew]==1)
                    {
                        vis[xnew][ynew]=2;
                        q.push({{xnew,ynew},t+1});
                        ans=max(ans,t+1);
                    }
                }
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(vis[i][j]==1)return -1;
            }
        }
        return ans;
    }