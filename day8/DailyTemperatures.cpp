class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        int i=n-1;
        stack<pair<int,int>>st;
        while(i>=0)
        {
            if(st.empty())st.push({temperatures[i],i});
            else
            {
                while(!st.empty() && st.top().first<=temperatures[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    ans[i]=(st.top().second-i);
                }
                st.push({temperatures[i],i});
            }
            i--;
        }
        return ans;
    }
};