class Solution {
public:
    string smallestNumber(string pattern) {
        vector<char> arr;
        int count = 1;
        string res="";
        for(int i=0;i<=pattern.size();i++,count++){
            arr.push_back(count+'0');
            if(pattern[i]=='I' || i==pattern.size()){
                if(!arr.empty()){
                    for(int i=arr.size()-1;i>=0;i--){
                        res+=arr[i];
                    }
                }
                arr.clear();
            }
        }
        return res;
    }
};