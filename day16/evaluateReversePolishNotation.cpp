#include<iostream>
class Solution {
public:
    int operate(int a,int b,string s)
    {
        if(s=="+")return a+b;
        else if(s=="-")return a-b;
        else if(s=="/")return a/b;
        else return a*b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="/" || tokens[i]=="*")
            {
               int b=st.top();st.pop();
               int a=st.top();st.pop();
               int ans=operate(a,b,tokens[i]);
               st.push(ans);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};