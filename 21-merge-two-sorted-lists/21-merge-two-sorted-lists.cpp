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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*p,*q,*r;
        p = list1;
        q = list2;
        if(p==NULL && q==NULL)
            return r;
        if(p==NULL )
            return q;
        if(q==NULL)
            return p;
        
        if(p->val<=q->val){
            r = p;
            p = p->next;
            r->next=NULL; 
        }else{
            r = q;
            q = q->next;
            r->next=NULL;
            
        }
        ListNode *res = r;
         while(p!=NULL && q!=NULL){
             if(p->val<=q->val){
                 r->next = p;
                 r = p;
                 p = p->next;
                 r->next=NULL;
             }else{
                 r->next = q;
                 r = q;
                 q = q->next;
                 r->next=NULL;
             }
         }
        if(p==NULL){
            r->next = q;
        }
            
        if(q==NULL){
            r->next = p;
        }
            
            
           return res; 
            
            
            
            
            
            
        
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
};;