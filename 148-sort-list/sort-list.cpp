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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);
        return merge(left, right);

    }
    ListNode* merge(ListNode* l, ListNode* r){
        ListNode dummy(0);
        ListNode* tail=&dummy;
        while(l!=NULL && r!=NULL){
        if(l->val<r->val){
            tail->next=l;
            l=l->next;
        }
        else{
            tail->next=r;
            r=r->next;
        }
        tail=tail->next;
        }
        
        if(l)
           tail->next=l;
        if(r)
           tail->next=r;
        return dummy.next;
    }
};