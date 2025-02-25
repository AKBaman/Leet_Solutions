class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const  int mod = 1e9 + 7;
        int odd_count = 0,even_count=1,prefix=0,result=0;
        
        for(int n :  arr){
            prefix+=n;

            if(prefix%2==0){
                result= ( result + odd_count)%mod;
                even_count++;
            }
            else{
                result = (result + even_count)%mod;
                odd_count++;
            }
        }

        return result;
    }
};