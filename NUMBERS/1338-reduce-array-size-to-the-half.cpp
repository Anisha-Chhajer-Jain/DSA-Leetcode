class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int n :arr){
            freq[n]++;
        }
        multiset<int,greater<int>>ms;
        for(auto p:freq){
            ms.insert(p.second);
        }
        int removed=0,steps=0,half=arr.size()/2;
        for(int count:ms){
            removed+=count;
            steps++;
            if(removed>=half){
                break;
            }
        }
        return steps;
    }
};