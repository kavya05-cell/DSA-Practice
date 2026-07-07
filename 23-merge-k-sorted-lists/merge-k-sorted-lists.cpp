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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>all;
        for(auto list:lists){
            while(list!=NULL){
                all.push_back(list->val);
                list=list->next;
            }
        }
        sort(all.begin(),all.end());
        ListNode*dummy=new ListNode(0);
        ListNode* cur=dummy;
        for(int val:all){
            cur->next=new ListNode(val);
            cur=cur->next;
        }
        return dummy->next;
    }
};
