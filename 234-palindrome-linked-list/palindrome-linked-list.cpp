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
    ListNode* listReverse(ListNode* head,ListNode* prev){
         if(head==NULL){
            return prev;
        }
        ListNode* temp = new ListNode(head->val);
        temp->next = prev;
        return listReverse(head->next,temp);
    }

    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        //reverse the linked list from middle then compare the two list;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow;
        mid = listReverse(mid,nullptr);
        // while(mid){
        //     cout<<mid->val<<" ";
        //     mid = mid->next;
        // }
        while(mid){
            if(head->val != mid->val){
                return false;
            }
            head = head->next;
            mid = mid->next;
        }

        return true;
    }
};