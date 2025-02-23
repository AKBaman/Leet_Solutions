/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* fast = node->next;
        while(fast){
            node->val = fast->val;
            if(fast->next==NULL){
                break;
            }
            node = node->next;
            fast = fast->next; 
        }
        node->next = NULL;   
    }
};