class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string ans=strs[0];
       for(int i=1;i<strs.size();i++)
       {
        //  int cnt=0;
         int j=0;
         while(j<ans.length() && j<strs[i].length())
         {
            if(ans[j]==strs[i][j])j++;
            else break;
         }
         if(j<ans.length())
         {
            ans=ans.substr(0,j);
         }
       } 
       return ans;
    }
};