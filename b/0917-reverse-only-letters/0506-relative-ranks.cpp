class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>res;
        multiset<int,greater<int>> ms(score.begin(),score.end());
        for(int s:score){
            auto it=ms.find(s);
            int rank= distance(ms.begin(),it)+1;
            if(rank==1){
                res.push_back("Gold Medal");
            }
            else if(rank==2){
                res.push_back("Silver Medal");
            }
            else if(rank==3){
                res.push_back("Bronze Medal");
            }
            else{
                res.push_back(to_string(rank));
            }
        }
        return res;
    }
};