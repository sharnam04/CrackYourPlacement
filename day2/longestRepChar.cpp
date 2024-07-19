class Solution {
public:
    int characterReplacement(string s, int k) {
        int hashmap[26]={0};
        int l=0,r=0,maxlen=0,maxfreq=0;
        while(r<s.length() && l<=r)
        {
            hashmap[s[r]-'A']++;
            maxfreq=max(maxfreq,hashmap[s[r]-'A']);
            if(r-l+1-maxfreq >k)
            {
                hashmap[s[l]-'A']--;
                l++;
            }
            else
            {
              maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};