class Solution {
public:
    int minimumPushes(string word) {
       map<char,int> freqmap;

       for(auto ch : word){
        freqmap[ch]++;
       }

       vector<pair<char,int>>list(freqmap.begin(),freqmap.end());

       sort(list.begin(),list.end(),[](auto& a,auto& b){
            return a.second > b.second;
       });
        int uni =0,ans=0,val=1;
       for(auto[ch,count] : list){
        if(uni == 8){
            uni=0;
            val++;
        }
        ans+=(val*count);
        uni++;
       }
       return ans;
        
    }
};