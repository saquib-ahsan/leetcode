/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

vector<int> nodes;

class Solution {
private:
    void dfs(Node *head) {
        if(!head) return;
        
        nodes.push_back(head->val);
        dfs(head->child);
        dfs(head->next);
    }
    
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        
        nodes.clear();
        dfs(head);
        
        Node *ans = new Node;
        ans->val = nodes[0], ans->prev = ans->next = ans->child = nullptr;
        Node *previous = ans, *tail = ans;
        for(int i = 1; i < (int)nodes.size(); ++i) {
            tail->next = new Node;
            tail = tail->next;
            
            tail->val = nodes[i], tail->prev = previous;
            tail->next = tail->child = nullptr;
            
            previous = previous->next;
        }
        
        return ans;
    }
};
