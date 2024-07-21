class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long sum=0;
        vector<vector<int>>ans;
        for(int i=0;i<=n-4;i++)
        {
            if (i >0 && nums[i] == nums[i - 1])
                continue;
           sum=nums[i];
           for(int j=i+1;j<=n-3;j++)
           {
            if (j>i+1 && nums[j] == nums[j-1])
            continue;
            sum+=nums[j];
            int k=j+1;int l=n-1;vector<int>v(4);
            while(k<l && k<n-1 && l>2)
            {
                sum+=(nums[k]+nums[l]);
                if(sum==target)
                {
                    v={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(v);
                    k++;l--;
                    while(k<l && nums[k]==nums[k-1])k++;
                    while(k<l && nums[l]==nums[l+1])l--;
                }
                else if(sum<target)
                {
                    k++;
                }
                else if(sum>target)
                {
                    l--;
                }
                sum=nums[i]+nums[j];
            }
            sum=nums[i];
           }
        }
        // vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};