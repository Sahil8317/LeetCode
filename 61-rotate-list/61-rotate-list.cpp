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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int len = 1;
        ListNode *p = head;
        while(p->next!=NULL){
            len++;
            p = p->next;
        }
        k = k%len;
        p->next = head;
        k = len-k;
        p = head;
        for(int i=0;i<k-1;i++){
           p =p->next; 
        }
        head = p->next;
        p->next = NULL;
        
        return head;
        
     }
};
