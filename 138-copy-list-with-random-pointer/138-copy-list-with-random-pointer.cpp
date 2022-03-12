/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        Node *p = head,*t=NULL,*last;
         map<Node*,Node*>m;
        while(p!=NULL){
            Node *temp = new Node(p->val);
            temp->next = p->next;
            if(!t){
               t = temp;
               t->next = NULL;
                last = t;
                m[p]= t; 
            }else{
                last->next = temp;
                last = temp;
                m[p] = temp;
            }
            p = p->next;
        }
        p = t;
        last = head;
        while(p!=NULL){
            if(last->random){
               p->random =  m[last->random];
            }else{
                p->random = NULL;
            }
            p = p->next;
            last = last->next;
        }
        
        return m[head];
    }
};