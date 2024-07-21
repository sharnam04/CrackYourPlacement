#include <bits/stdc++.h> 
vector<pair<char,int>> duplicate_char(string s, int n){
    // Write your code here.
    vector<pair<char,int>>ans;
    int hashmap[256]={0};
    for(int i=0;i<n;i++)
    {
      hashmap[s[i]-'A']++;
    }
    for(int i=0;i<256;i++)
    {
        if(hashmap[i]>=2)
        {
            ans.push_back({i+'A',hashmap[i]});
        }
    }
    return ans;
}