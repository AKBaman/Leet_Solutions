class Solution {
public:
    bool isPrime(int n){
        if(n==0 || n==1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>ans(2,0);
        vector<int>arr;

        for(int i=left;i<=right;i++){
            if(isPrime(i)){
                arr.push_back(i);
            }
        }

        if(arr.size()<2)  return {-1,-1};

        int diff=INT_MAX;
        for(int i=1;i<arr.size();i++){
            if(diff > arr[i]-arr[i-1]){
                diff = arr[i]-arr[i-1];
                ans[0] = arr[i-1];
                ans[1] = arr[i];
            }
        }
        return ans;
    }
};