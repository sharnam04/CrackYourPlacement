class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        if(n%2!=0)return false;

        stack<char>st;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(s[i]==')' || s[i]=='}' || s[i]==']')
            {
                if(!st.empty() && ((s[i]==')'&& st.top()=='(') || (s[i]=='}'&& st.top()=='{') || (s[i]==']'&& st.top()=='[')))
                {
                st.pop();
                }
                else
                {
                return false;
                }
            
            }
        }
        if(!st.empty())return false;
        
        return true;
    }
};