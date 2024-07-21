class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
           mpp[nums[i]]++;
           if(mpp[nums[i]]>(n/2))return nums[i];
        }
        return -1;
    }
};