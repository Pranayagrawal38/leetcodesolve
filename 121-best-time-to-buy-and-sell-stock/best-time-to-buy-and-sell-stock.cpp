class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp=INT_MAX,prof=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minp)
            minp=prices[i];
            if(prices[i]-minp>prof)
            prof=prices[i]-minp;



        }
        return prof;
       
        
    }
};