class FindSumPairs {
public:
    vector<int> v1;
    vector<int> v2;
    unordered_map<int,int> hash;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->v1 = nums1;
        this->v2 = nums2;

        for(auto n : v2){
            hash[n]++;
        }
    }
    
    void add(int index, int val) {
        int old  = v2[index];
        hash[old]--;

        if(hash[old]==0){
            hash.erase(old);
        }

        v2[index]+=val;
        hash[v2[index]]++;
    }
    
    int count(int tot) {

        
        int ans = 0;

        for(auto n : v1){
            int val = tot-n;
            ans+=hash[val];
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */