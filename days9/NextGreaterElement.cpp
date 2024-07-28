class Solution {
public:
    unordered_map<int,int>nge(vector<int>& nums2)
    {
        unordered_map<int,int>next;
        int m=nums2.size();
        stack<int>st;
        for(int i=m-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            if(!st.empty())next[nums2[i]]=st.top();
            else if(st.empty())next[nums2[i]]=-1;
            st.push(nums2[i]);
        }
        return next;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp=nge(nums2);
        int n=nums1.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
          if(mpp.find(nums1[i])!=mpp.end())
          {
            ans[i]=mpp[nums1[i]];
          }
        }
        return ans;
    }
};