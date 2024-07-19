class Solution {
public:
    bool solve(int ind,int i,int j,vector<vector<char>>& board, string word,vector<vector<int>>&vis)
    {
        if(ind==word.length())return true;
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0)return false;

        int dirx[]={-1,0,1,0};
        int diry[]={0,-1,0,1};
        if(board[i][j]!=word[ind] || vis[i][j]==1)return false;
        else if(board[i][j]==word[ind] && vis[i][j]==-1)
        {
            vis[i][j]=1;
            bool ans=0;
            for(int t=0;t<4;t++)
            {
               ans=ans||(solve(ind+1,i+dirx[t],j+diry[t],board,word,vis));
            }
            if(ans==false){
                vis[i][j]=-1;
                return false;
            }
        }
        return true;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    vector<vector<int>>vis(m,vector<int>(n,-1));
                    if(solve(0,i,j,board,word,vis))
                    {
                       return true;
                    }
                }
            }
        }
        return false;
    }
};