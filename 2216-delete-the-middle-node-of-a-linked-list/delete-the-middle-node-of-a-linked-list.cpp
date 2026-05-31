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
        if(head==nullptr || head->next ==nullptr) return nullptr;
        int n=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        int target=n/2;
        temp=head;
        for(int i=0;i<target-1;i++)
            temp=temp->next;
        ListNode* middleNode=temp->next;
        temp->next=temp->next->next;
        delete middleNode;
        return head;
    }
};