class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.length();
       int i=0,j=n-1;
       int cnt=0;
       while(i<=j && cnt<2)
       {
        if(s[i]==s[j])
        {
            i++;j--;
        }
        else if(s[i]!=s[j])
        {
            i++;cnt++;
        }
       }
       if(cnt<=1)return true;
       i=0,j=n-1,cnt=0;
       while(i<=j && cnt<2)
       {
        if(s[i]==s[j])
        {
            i++;j--;
        }
        else if(s[i]!=s[j])
        {
            j--;cnt++;
        }
       }
       if(cnt<=1)return true;
       return false;
    }
};