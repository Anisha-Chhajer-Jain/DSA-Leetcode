class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0;
       int smallest=INT_MAX;
       for(int i=0;i<prices.size();i++){
           smallest=min(smallest,prices[i]);
           result=max(result,prices[i]-smallest);
       }
       return result;
    }
};