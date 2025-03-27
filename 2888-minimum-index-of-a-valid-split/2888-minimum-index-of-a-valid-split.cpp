class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int ,int> freq;

        int mode = -1,maxfreq=0;

        for(int num : nums){
            freq[num]++;
            if(freq[num] > maxfreq){
                maxfreq = freq[num];
                mode = num;
            }
        }

        int n = nums.size(),currfreq = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == mode){
                currfreq++;
            }

            if(currfreq*2  > i+1 && (maxfreq-currfreq) * 2 > (n-i-1)){
                return i;
            }
        }
        return -1;
    }
};