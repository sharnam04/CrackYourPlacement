class Solution {
public:
    string intToRoman(int num) {
        map<int,string,greater<int>>mpp;
        mpp[1]="I";mpp[5]="V";mpp[10]="X";mpp[50]="L";mpp[100]="C";mpp[500]="D";mpp[1000]="M";
        mpp[4]="IV";mpp[9]="IX";mpp[40]="XL";mpp[90]="XC";mpp[400]="CD";mpp[900]="CM";
        string ans="";
        
          for(auto it:mpp)
          {
            while(num>=it.first)
            {
                ans+=it.second;
                num-=it.first;
            }
          }
        return ans;
    }
};