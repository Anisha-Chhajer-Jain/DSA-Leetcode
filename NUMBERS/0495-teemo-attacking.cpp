class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) 
    {
        int n = timeSeries.size();
        int ans = 0;
        ans+=duration;
        for(int i=n-2;i>=0;i--)
        {
            if(timeSeries[i]+duration < timeSeries[i+1])
            {
                ans+=duration;
            }
            else
            {
                ans+=timeSeries[i+1]-timeSeries[i];
            }
        }
        return ans;
    }
};