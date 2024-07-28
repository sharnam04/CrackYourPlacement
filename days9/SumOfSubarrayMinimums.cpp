using LL=long long;
class Solution {
public:
void nextSmaller(vector<int>& arr,vector<int>&nse,int n)
{
    stack<pair<int,int>>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top().first>=arr[i])
        {
            st.pop();
        }
        nse[i]=(st.empty() ? n : st.top().second);
        st.push({arr[i],i});
    }
}
void prevSmaller(vector<int>& arr,vector<int>&pse,int n)
{
    stack<pair<int,int>>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top().first>arr[i])
        {
            st.pop();
        }
        pse[i]=(st.empty() ? -1 : st.top().second);
        st.push({arr[i],i});
    }
}
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int mod=1e9 + 7;
        int n=arr.size();
        vector<int>pse(n,-1);//to cover edge cases we wrote 0 instead of -1 {1,1}is this is array we repeat answer
        vector<int>nse(n,n);
        nextSmaller(arr,nse,n);
        prevSmaller(arr,pse,n);
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            LL left=i-pse[i];
            LL right=nse[i]-i;
            ans=(ans+(right*left*1LL*arr[i])%mod)%mod;
        }
        return ans;
    }
};
