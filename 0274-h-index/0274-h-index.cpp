class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(),c.end());
        
        int start=0,end=c[c.size()-1],mid ,ans;
        while(start<=end){
            mid = start +(end-start)/2;
            int count=0;
            for(int i=0;i<c.size();i++){
                if(c[i]>=mid){
                    count++;
                }
            }
            if(count >= mid){
                ans = mid;
                start=mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};