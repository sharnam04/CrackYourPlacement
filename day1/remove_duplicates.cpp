class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int cnt=0;
        int i=0,j=1;
        while(j<n)
        {
           if(nums[i]!=nums[j] && i+1<n)
           {
            nums[i+1]=nums[j];
            i++;
           }
            j++;
        }
        return i+1;
    }
};