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
    int getDecimalValue(ListNode* head) {
        stack<int> st;
        while(head){
            st.push(head->val);
            head = head->next;
        }

        long long res=0,prod=1;
        while(!st.empty()){
            res+=prod*st.top();
            prod = prod<<1;
            st.pop();
        }

        return res;
    }
};