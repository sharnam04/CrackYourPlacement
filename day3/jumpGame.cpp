class Solution {
public:
    bool canJump(vector<int>& nums) {
       int maxind=0;
       int i=0,n=nums.size();
       while(maxind>=i && i<n)
       {
          if(maxind>=n-1)return true;

          maxind=max(maxind,nums[i]+i);
          i++;
       } 
       return false;
    }
};