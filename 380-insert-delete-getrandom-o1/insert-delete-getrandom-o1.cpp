class RandomizedSet {
public:
    unordered_set<int> set;
    template<typename S>
    auto select_random(const S &s, size_t n) {
        auto it = std::begin(s);
  // 'advance' the iterator n times
        std::advance(it,n);
        return it;
    }
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(set.find(val) == set.end()){
            set.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(set.find(val)!=set.end()){
            set.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        // auto r = rand() % set.size();
        // auto n = *select_random(set,r);
        // return n;
        int idx = rand()%set.size();
        auto it = set.begin();
        for (int i = 0; i < idx; i++)
        {
            it++;
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */