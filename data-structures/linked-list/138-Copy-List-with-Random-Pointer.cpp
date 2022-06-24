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
        if(!head) return head;
        
        Node *ans, *last;
        ans = last = new Node(head->val);
        
        Node *p = head->next;
        while(p) {
            last->next = new Node(p->val);
            last = last->next;
            
            p = p->next;
        }
        
        // copy random nodes;
        Node *q = ans;
        p = head;
        while(p) {
            Node *ran = head, *tmp = ans;
            while(p->random != ran) {
                ran = ran->next;
                tmp = tmp->next;
            }
            q->random = tmp;
            
            q = q->next;
            p = p->next;
        }
        
        return ans;
    }
};
