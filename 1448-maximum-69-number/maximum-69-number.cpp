class Solution {
public:
    int maximum69Number (int num) {
        vector<int> arr;
        while(num>0){
            cout<<num%10<<" ";
            arr.push_back(num%10);
            num/=10;
        }
        reverse(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i] == 6){
                arr[i] = 9;
                break;
            }
        }
        int currMax= 0;
        for(int i=0;i<arr.size();i++){
            currMax = currMax*10 + arr[i];
        }

        return max(currMax,num);

    }
};