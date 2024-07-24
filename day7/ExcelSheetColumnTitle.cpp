class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber>0)
        {
            columnNumber--;
            int x=columnNumber%26;
            ans=char(x+'A')+ans;
            columnNumber=columnNumber/26;
        }
        return ans;
    }
};