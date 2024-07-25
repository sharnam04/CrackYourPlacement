class Solution
{
    int calc(char c,int a,int b)
    {
        if(c=='+')return a+b;
        else if(c=='-')return a-b;
        else if(c=='*')return a*b;
        else if(c=='/')return a/b;
        else if(c=='^')return pow(a,b);
    }
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        // Your code here
        int n=s.length();
        int i=0;stack<int>st;
        while(i<n)
        {
           if(s[i]>='0' && s[i]<='9')
           {
               st.push(s[i]-'0');
           }
           else
           {
               char op=s[i];
               int a=st.top();st.pop();
               int b=st.top();st.pop();
               int ans=calc(op,b,a);
               st.push(ans);
           }
           i++;
        }
        return (st.top());
    }
};

