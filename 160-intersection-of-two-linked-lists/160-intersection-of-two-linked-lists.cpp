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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode *>v1;
        vector<ListNode *>v2;
        ListNode *p,*q;
        p = headA;
        q = headB;
        while(p!=NULL){
            v1.push_back(p);
            p = p->next;
        }
        while(q!=NULL){
            v2.push_back(q);
            q = q->next;
        }
        p = NULL;
        while(!v1.empty() && !v2.empty() && v1.back()==v2.back()){
            p = v1.back();
            v1.pop_back();
            v2.pop_back();
        }
        return p;
    }
};