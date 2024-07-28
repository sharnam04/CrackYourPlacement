class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        // code here
        int top=0,bottom=n-1;
        while(top<bottom)
        {
            if(M[top][bottom]==1)top++;
            else if(M[bottom][top]==1)bottom--;
            else
            {
                top++;bottom--;
            }
        }
        //Top==Bottom
        if(top>bottom)return -1;
        for(int i=0;i<n;i++)
        {
            if(i==top)continue;
            if(M[top][i]==0 && M[i][top]==1){}
            else return -1;
            
        }
        return top;
    }
};