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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL || head==NULL) return NULL;
        ListNode* temp = head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        count/=2;
        count-=1;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(count--){
            if(slow->next!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast = fast->next;
            }
        }
        slow->next = fast->next;
        delete fast;
        return head;
    }
};