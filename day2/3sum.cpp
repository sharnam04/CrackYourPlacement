class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        set<vector<int>>st;
        int sum;
        for(int i=0;i<n-2;i++)
        {
            sum=nums[i];
            int j=i+1;int k=n-1;
            while(j<k)
            {
                sum+=(nums[j]+nums[k]);
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else if(sum==0)
                {
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                }
                sum=nums[i];
            }
        }
        ans.insert(ans.begin(),st.begin(),st.end());
            return ans;
    }
};