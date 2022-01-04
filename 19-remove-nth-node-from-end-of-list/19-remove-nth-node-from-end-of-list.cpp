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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *p,*q;
      int len = 0;
        p = head;
        while(p!=NULL){
            len++;
            p = p->next;
        }
        if(len==1){
            q = NULL;
            return q;
        }
        len = len-n;
        p= head;
        if(len==0){
            head = head->next;
            return head;
        }
        for(int i=0;i<len;i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
        return head;
    }
};