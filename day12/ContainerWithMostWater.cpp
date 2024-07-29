class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int maxi=0;
        int ans=0;
        while(i<j)
        {
            int width=j-i;
            int maxheight=min(height[i],height[j]);
            ans=max(ans,width*maxheight);
            if(height[i]<=height[j])i++;
            else if(height[i]>height[j])j--;
        }
        return ans;
    }
};