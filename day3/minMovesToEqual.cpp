class Solution {
public:
    int solve(int ind,vector<int>& nums)
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int x=abs(nums[i]-nums[ind]);
            ans+=x;
        }
        return ans;
    }
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n%2!=0)
        {
            return solve(n/2,nums);
        }
        else
        {
            return min(solve((n/2)-1,nums),solve(n/2,nums));
        }
    }
};