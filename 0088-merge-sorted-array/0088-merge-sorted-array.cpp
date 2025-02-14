class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=0;
        vector<int>temp;
        for(int num : nums1){
            temp.push_back(num);
        }
        while(i<m && j<n){
            if(temp[i] < nums2[j] ){
                nums1[k] = temp[i];
                i++;k++;
            }else{
                nums1[k] = nums2[j];
                j++;k++;
            }
        }
        for( ;i<m;i++){
            nums1[k++] = temp[i];
        }
        for( ;j<n;j++){
            nums1[k++] = nums2[j];
        }
        
    }
};