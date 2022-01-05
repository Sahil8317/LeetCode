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
    bool hasCycle(ListNode *head) {
        ListNode *slow,*fast;
        slow = head;
        fast = head;
        while(fast!=NULL && slow!=NULL){
            fast = fast->next;
            if(fast==slow)
                return true;
            slow= slow->next;
            if(fast)
                fast = fast->next;
            else
                return false;
        }
        return false;
    }
};