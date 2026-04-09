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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode*cur=head;
        while(cur!=NULL){
            while(!st.empty() && st.top()->val < cur->val)
                  st.pop();
            st.push(cur);
            cur=cur->next;
        }
        ListNode* newhead=NULL;
        while(!st.empty()){
            ListNode*p=st.top();
            st.pop();
            p->next=newhead;
            newhead=p;
        }
        return newhead;
        

    }
};