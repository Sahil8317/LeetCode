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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        if(head->next==NULL) return head;
        ListNode *p = new ListNode(-101);   // out of bound element
        ListNode *q = head;
        ListNode *r = head->next;
        ListNode *newHead = NULL;
        while(r!=NULL){
            if(q->val==r->val){
                while( r!=NULL && r->val==q->val){
                    r = r->next;
                }
                p->next = r;
                if(p->val==-101) head = r;
                q = r;
                if(r) r = r->next;
            }else{
                p = q;
                q = r;
                if(r) r = r->next;
            }
        }
      
        return head;
    }
};