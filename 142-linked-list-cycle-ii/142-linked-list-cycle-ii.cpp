/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int> m;
        ListNode *p = head;
        while(p){
            if(m[p]==1){
              return p;  
            }else{
                m[p]=1; 
            }
            p = p->next;
        }
        return NULL;
    }
};