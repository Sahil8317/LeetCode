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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> stk;
        int count = 0;
        ListNode *p = head;
        ListNode *prev = NULL;
        ListNode *head2=NULL;
        int fhead = 0;
       
        while(p!=NULL){   
            count++;
            stk.push_back(p);
              ListNode *temp =NULL;
            if(count==k){
                fhead++;
                count = 0;
                ListNode*t = stk.back();
                if(fhead==1)
                    head = t;
                else
                    head2 = t;
                t = t->next;
               
                while(!stk.empty()){
                    temp = stk.back();
                     stk.pop_back();
                    if(!stk.empty())
                    temp->next = stk.back();   
                }
                temp->next = t;
                if(prev)
                prev->next= head2;
                
            }
            if(temp){
              p = temp;
                prev = temp;
            }
            p = p->next;
        }
        return head;
        
    }
};