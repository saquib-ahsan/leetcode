/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        
        queue<Node *> p, q;
        p.push(root);
        
        while(!p.empty() || !q.empty()) {
            Node *temp = p.front();
            p.pop();
            temp->next = (p.empty()) ? nullptr : p.front();
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            
            if(p.empty()) {
                while(!q.empty()) {
                    p.push(q.front());
                    q.pop();
                }
            }
        }
        
        return root;
    }
};
