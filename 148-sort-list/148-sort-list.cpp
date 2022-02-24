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
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
       vector<int> res;
         ListNode * p = head;
        while(p){
            res.push_back(p->val);
            p = p->next;
        }
        sort(res.begin(),res.end());
        p = head;
        for(auto i:res){
            p->val = i;
            p = p->next;
        }
        return head;
    }
};