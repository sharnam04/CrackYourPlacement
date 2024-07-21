class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0;int n=cardPoints.size();
        int ans=0;
        for(int i=0;i<k;i++)
        {
          lsum+=cardPoints[i];
        }

        //window is of k size combined from front and back;
        int rsum=0;
        ans=lsum;
        int r=n-1,l=k-1;
        while(l>=0)
        {
            lsum-=cardPoints[l--];
            rsum+=cardPoints[r--];
             ans=max(ans,rsum+lsum);
        }
        return ans;

    }
};