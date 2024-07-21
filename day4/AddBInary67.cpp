class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.length();
        int n=b.length();
        string ans="";
        int i=m-1,j=n-1;
        int carry=0;
        while(i>=0 || j>=0 || carry)
        {
            int sum=carry;
            if(i>=0)sum+=(a[i--]-'0');
            if(j>=0)sum+=(b[j--]-'0');
            ans=char(sum%2 + '0')+ans;
            carry=sum/2;
        }
        return ans;
    }
};