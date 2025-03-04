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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int d1,d2;
            if(l1!=nullptr){
                d1 = l1->val;
            }
            else{
                d1 = 0;
            }
            if(l2!=nullptr){
                d2 = l2->val;
            }
            else{
                d2 = 0;
            }

            int sum = d1+d2+carry;
            int d = sum%10;
            carry = sum/10;
            
            ListNode* newNode = new ListNode(d);
            tail->next = newNode;
            tail = tail->next;
            
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;

        }
        ListNode* res = head->next;
        delete head;
        return res;
    }
};