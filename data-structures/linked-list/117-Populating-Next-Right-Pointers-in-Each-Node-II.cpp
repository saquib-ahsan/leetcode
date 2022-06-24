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

// SPACE OPTIMIZED SOLUTION (FOLLOW UP)




/////////////////////////////////////////////////////////////////////////////////////
#define sz(x) (int)(x).size()

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        
        queue<Node *> p, q;
        p.push(root);
        
        while(sz(p)) {
            Node *tmp = p.front();
            p.pop();
            tmp->next = (sz(p)) ? p.front() : nullptr;
            
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            
            if(sz(p) == 0) {
                while(sz(q)) {
                    p.push(q.front());
                    q.pop();
                }
            }
        }
        
        return root;
    }
};
