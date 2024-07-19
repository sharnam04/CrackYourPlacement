#include<bits/stdc++.h>
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
        int l=0,r=m-1,t=0,b=n-1;
        int total=m*n;int cnt=0;
        while(l<=r && t<=b && total>cnt)
        {
            //l to r
            for(int i=l;i<=r ;i++)
            {
               ans.push_back(matrix[t][i]);
               cnt++;
            }
            t++;

            //t to b
            for(int i=t;i<=b && total>cnt;i++)
            {
               ans.push_back(matrix[i][r]);
               cnt++;
            }
            r--;
            //r to l
            for(int i=r;i>=l && total>cnt;i--)
            {
               ans.push_back(matrix[b][i]);
               cnt++;
            }
            b--;
            //b to t
            for(int i=b;i>=t && total>cnt;i--)
            {
               ans.push_back(matrix[i][l]);
               cnt++;
            }
            l++;
        }
        return ans;
    }
};