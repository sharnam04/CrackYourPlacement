class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int>st;
        st.push_back(INT_MAX);int res=0;
        for(int i=0;i<arr.size();i++)
        {
            while(st.back()<=arr[i])
            {
                int x=st.back();
                st.pop_back();
                res+=(x*min(arr[i],st.back()));
            }
            st.push_back(arr[i]);
        }

        for(int i=2;i<st.size();i++)
        {
            res+=(st[i]*st[i-1]);
        }
        return res;
    }
};