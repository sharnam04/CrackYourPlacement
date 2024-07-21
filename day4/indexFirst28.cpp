class Solution {
public:
    int strStr(string haystack, string needle) {
        int l=needle.length();
        int n=haystack.length();
        if(n<l)return -1;
        for(int i=0;i<=(n-l);i++)
        {
          if(haystack.substr(i,l)==needle)return i;
        }
        return -1;
    }
};