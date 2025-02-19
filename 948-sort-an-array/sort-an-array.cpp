class Solution {
public:
    void Merge(vector<int>&arr,int start,int mid,int end){
        //Make a temporary array to store sorted elements
        vector<int> temp(end - start + 1);

        int left=start , right=mid+1 , index=0;

        while(left <=  mid && right <= end){

            if(arr[left] <=  arr[right]){
                temp[index++] = arr[left++];
            }
            else{
                temp[index++] = arr[right++];
            }
        }

        //Remaing Copy elements 
        //Copy from Left array
        while(left <= mid){
            temp[index++] = arr[left++];
        }
        //Copy the right array
        while(right <= end){
            temp[index++] =  arr[right++];
        }

        //Now Copy the temp array in original
        index=0;

        while(start <=  end){
            arr[start++] = temp[index++];
        }

    }
    void MergeSort(vector<int>&arr,int start,int end){
        //All singular array are already sorted
        if(start == end) return;
        //Finding Mid value (Dividing the array)
        int mid = start + (end-start)/2;
        //Array Division
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,end);

        //Merging the array
        Merge(arr,start,mid,end);

    }
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums,0,nums.size()-1);
        return nums;
    }
};