class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
       multiset<int> ms(gifts.begin(),gifts.end());
       while(k--){
        auto it=prev(ms.end());
        int largest=*it;
        ms.erase(it);
        ms.insert(sqrt(largest));
       }
       long long sum=0;
       for(int g:ms){
        sum+=g;
       }
       return sum;
    }
};