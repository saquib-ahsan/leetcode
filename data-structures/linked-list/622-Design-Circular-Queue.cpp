struct Node {
    int val;
    Node *prev, *next;
    // constructors
    Node() : val(0), prev(nullptr), next(nullptr) {}
    Node(int val) : val(val), prev(nullptr), next(nullptr) {}
};

class MyCircularQueue {
private:
    Node *head;
    int limit, sz;
    
public:
    MyCircularQueue(int k) {
        head = nullptr;
        sz = 0;
        limit = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        
        if(sz == 0) {
            head = new Node(value);
            head->next = head->prev = head;
        } else {
            Node *tail = head->prev;
            Node *tmp = new Node(value);
            tmp->next = head;
            head->prev = tmp;
            
            tail->next = tmp;
            tmp->prev = tail;
            
            head = tmp;
        }
        
        ++sz;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        
        if(sz == 1) {
            delete head;
        } else {
            Node *tail = head->prev;
            tail->prev->next = head;
            head->prev = tail->prev;
            
            tail->next = tail->prev = nullptr;
            delete tail;
        }
        
        --sz;
        return true;
    }
    
    int Front() {
        if(sz < 2) return Rear();
        return head->prev->val;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return head->val;
    }
    
    bool isEmpty() {
        return sz == 0;
    }
    
    bool isFull() {
        return sz == limit;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
