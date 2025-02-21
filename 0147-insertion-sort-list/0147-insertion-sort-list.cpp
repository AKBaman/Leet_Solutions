/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void insertionSort(vector<int>&arr,int n){
        for(int i=1;i<n;i++){ 
            //This i-->Indicates number of rounds (n-1)
            // There are two ways to compare either from left or right
            for(int j=i;j>0;j--){ 
            
                if(arr[j]<arr[j-1]){
                    swap(arr[j],arr[j-1]);
                }else{
                    break;
                }
            }
        }
    }
    ListNode* insertionSortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
            
        }
        insertionSort(arr,arr.size());
        temp = head;
        for(int n : arr){
            temp->val = n;
            temp=temp->next;
        }   
        return head;
    }
};