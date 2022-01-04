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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode*p,*q,*r,*head=NULL;
        int carry = 0,sum = 0;
        p = l1,q=l2;
        while(p!=NULL || q!=NULL || carry!=0){
            sum=0;
            if(p!=NULL){
                sum+=p->val;
                p = p->next;

            }
            if(q!=NULL){
                sum+=q->val;
                q = q->next;
            }
                
            sum+=carry;
            ListNode *node = new ListNode();
                node->val = sum%10;
                carry = sum/10;
                if(!head){
                    head = node;
                    r = head;
                }else{
                r->next = node;
                r = r->next;  
                }
        }
        return head;
    }
};
    