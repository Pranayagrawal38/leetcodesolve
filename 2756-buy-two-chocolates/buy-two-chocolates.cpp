class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int p;
        sort(prices.begin(),prices.end());
        int sum=prices[0]+prices[1];
        if(prices.size()>=2){
            if(sum<=money)
                p=money-sum;
            else
                p=money;
        }
        else{
            p=money;
        }
        return p;
    }
};