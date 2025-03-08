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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* temp = head;
        vector<int>arr;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }

        int start = left-1,end=right-1;
        while(start<=end){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
        temp=head;
        for(int i=0;i<arr.size();i++){
            if(temp==NULL)break;
            temp->val = arr[i];
            temp=temp->next;
        }

        return head;
    }
};