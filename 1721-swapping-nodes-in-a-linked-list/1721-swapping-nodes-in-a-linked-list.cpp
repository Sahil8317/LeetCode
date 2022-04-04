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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head) return head;
       int start = k-1;
       int n = 0;
        ListNode *t = head;
        while(t!=NULL){
            n++;
            t = t->next;
        }
        int last = n-k;
        ListNode*p=head,*q = head;
        for(int i=0;i<start;i++){
            p = p->next;
        }
        for(int i=0;i<last;i++){
            q = q->next;
        }
        int temp = p->val;
        p->val = q->val;
        q->val = temp;
        return head;
    }
    
};