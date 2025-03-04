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
    ListNode* Reversed(ListNode* head,ListNode* prev){
        if(head==NULL){
            return prev;
        }
        ListNode* temp = new ListNode(head->val);
        temp->next = prev;
        return Reversed(head->next,temp);
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        head = Reversed(head,nullptr);
        return head;
    }
};