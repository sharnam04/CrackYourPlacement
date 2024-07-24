class Solution {
private:
    void generate(int n,vector<string>&ans,string s,int open,int close)
    {
        if( open==close && close==n)
        {
            ans.push_back(s);
            return;
        }
        if(open<close)return;
        if(open<n)
        {
            generate(n,ans,s+"(",open+1,close);
        }
        if(close<open)
        {
        generate(n,ans,s+")",open,close+1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(n,ans,"",0,0);
        return ans;
    }
};