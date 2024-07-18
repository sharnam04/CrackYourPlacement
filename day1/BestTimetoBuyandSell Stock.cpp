class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0];
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
          ans=max(ans,prices[i]-minprice);
          if(prices[i]<minprice)
          {
            minprice=prices[i];
          }
        }
        return ans;
    }
};