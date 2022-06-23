struct Node {
    int val;
    Node *prev, *next;
    // constructors
    Node() : val(0), prev(nullptr), next(nullptr) {}
    Node(int val) : val(val), prev(nullptr), next(nullptr) {}
};

class MyCircularDeque {
private:
    Node *head, *tail;
    int sz, limit;
    
public:
    MyCircularDeque(int k) {
        head = tail = nullptr;
        sz = 0;
        limit = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(isEmpty()) {
            head = tail = new Node(value);
            ++sz;
            return true;
        }
        
        Node *tmp = new Node(value);
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
        ++sz;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        if(isEmpty()) return insertFront(value);
        
        tail->next = new Node(value);
        tail->next->prev = tail;
        tail = tail->next;
        ++sz;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        if(sz == 1) {
            delete head;
            --sz;
            return true;
        }
        
        Node *tmp = head;
        head = head->next;
        tmp->next = nullptr;
        head->prev = nullptr;
        delete tmp;
        --sz;
        return true;
    }
    
    bool deleteLast() {
        if(sz < 2) return deleteFront();
        
        tail = tail->prev;
        Node *tmp = tail->next;
        tail->next = nullptr;
        tmp->prev = nullptr;
        delete tmp;
        --sz;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return head->val;
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return sz == 0;
    }
    
    bool isFull() {
        return sz == limit;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
