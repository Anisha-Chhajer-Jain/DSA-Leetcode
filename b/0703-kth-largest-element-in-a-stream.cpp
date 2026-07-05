class KthLargest {
    multiset<int> ms;
    int sz;
public:
    KthLargest(int k, vector<int>& nums) {
        sz=k;
        for(int n :nums){
            add(n);
        }
    }
    
    int add(int val) {
        ms.insert(val);
        if(ms.size()>sz){
            ms.erase(ms.begin());
        }
        return *ms.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */