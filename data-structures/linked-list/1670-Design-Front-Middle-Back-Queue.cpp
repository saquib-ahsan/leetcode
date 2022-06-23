struct Node {
    int val;
    Node *prev, *next;
    // constructors
    Node() : val(0), prev(nullptr), next(nullptr) {}
    Node(int val) : val(val), prev(nullptr), next(nullptr) {}
};

class FrontMiddleBackQueue {
private:
    Node *head, *tail;
    int sz;
    
    pair<Node *, Node *> mid_and_mid_follower() {
        Node *fast, *mid, *mid_follower = nullptr;
        fast = mid = head;
        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                mid_follower = mid;
                mid = mid->next;
            }
        }
        
        return make_pair(mid, mid_follower);
    }
    
public:
    FrontMiddleBackQueue() {
        head = tail = nullptr;
        sz = 0;
    }
    
    void pushFront(int val) {
        if(sz == 0) {
            head = tail = new Node(val);
        } else {
            Node *tmp = new Node(val);
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
        
        ++sz;
    }
    
    void pushMiddle(int val) {
        if(sz < 2) return pushFront(val);
        
        pair<Node *, Node *> midstpair = mid_and_mid_follower();
        Node *mid = midstpair.first, *mid_follower = midstpair.second;
        
        mid_follower->next = new Node(val);
        mid_follower->next->prev = mid_follower;
        mid_follower = mid_follower->next;
        
        mid_follower->next = mid;
        mid->prev = mid_follower;
        ++sz;
    }
    
    void pushBack(int val) {
        if(sz == 0) return pushFront(val);
        
        tail->next = new Node(val);
        tail->next->prev = tail;
        tail = tail->next;
        ++sz;
    }
    
    int popFront() {
        if(sz == 0) return -1;
        
        int x = head->val;
        if(sz < 2) {
            head = tail = nullptr;
        } else {
            Node *tmp = head;
            head = head->next;
            head->prev = tmp->next = nullptr;
            delete tmp;
        }
        
        --sz;
        return x;
    }
    
    int popMiddle() {
        if(sz < 3) return popFront();
        
        pair<Node *, Node *> midstpair = mid_and_mid_follower();
        Node *mid = midstpair.first, *mid_follower = midstpair.second;
        
        int x = -1;
        if(sz&1) {
            x = mid->val;
            mid_follower->next = mid->next;
            mid->next->prev = mid_follower;
            
            mid->next = mid->prev = nullptr;
            delete mid;
        } else {
            x = mid_follower->val;
            Node *tmp = mid_follower->prev;
            tmp->next = mid;
            mid->prev = tmp;
            
            mid_follower->next = mid_follower->prev = nullptr;
            delete mid_follower;
        }
        
        --sz;
        return x;
    }
    
    int popBack() {
        if(sz < 2) return popFront();
        
        int x = tail->val;
        Node *tmp = tail;
        tail = tail->prev;
        tail->next = tmp->prev = nullptr;
        delete tmp;
        
        --sz;
        return x;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
