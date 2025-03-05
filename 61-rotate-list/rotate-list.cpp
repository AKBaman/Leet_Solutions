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
    ListNode* CreateList(vector<int>arr,int index,int n){
        if(index==n){
            return nullptr;
        }
        ListNode* temp = new ListNode(arr[index]);
        temp->next = CreateList(arr,index+1,n);
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        ListNode* temp = head;
        vector<int> ans;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }

        int  n=ans.size();
        k=k%n;
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            res[(i+k)%n] = ans[i];
        }

        head = CreateList(res,0,n);
        return  head;
    }
};