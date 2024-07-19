class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int i=0;
        int ans=0,sum=0;
        while(i<nums.size())
        {
            sum+=nums[i];
            // mpp[sum]++;
            int num=sum%k;
            if(num<0)
            {
                num=num+k;
            }
            if(mpp.find(num)!=mpp.end())
            {
                ans+=(mpp[num]);
            }
            mpp[num]++;
            i++;
        }
        return ans;
    }
};