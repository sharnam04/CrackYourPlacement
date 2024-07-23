class Solution {
private:
void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>& img,int prevcolor,int color)
{
    img[row][col]=color;    
    int n=image.size();
    int m=image[0].size();
    int dirx[]={0,1,0,-1};
    int diry[]={1,0,-1,0};
    for(int i=0;i<4;i++)
    {
        int row2=row+dirx[i];
        int col2=col+diry[i];
        if(row2>=0 && col2>=0 && row2<n && col2<m)
        {
            if( image[row2][col2]==prevcolor && img[row2][col2]!=color)
            {
                dfs(row2,col2,image,img,prevcolor,color);
            }
        }
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>img=image;
        int n=image.size();
        int m=image[0].size();
        // vector<vector<int>>vis(n,vector<int>(m,0));
        dfs(sr,sc,image,img,image[sr][sc],color);
        return img;
    }
};