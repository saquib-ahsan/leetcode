class MyLinkedList {
    ListNode *head;
    int len;    // length of the linked list
public:
    MyLinkedList() {
        head = nullptr;
        len = 0;
    }
    
    int get(int index) {
        if(index >= len) return -1;
        
        ListNode *temp = head;
        while(index--) temp = temp->next;
        return temp->val;
    }
    
    void addAtHead(int val) {
        if(head == 0) {
            head = new ListNode(val);
            ++len;
            return;
        }
        
        ListNode *temp = new ListNode(val, head);
        head = temp;
        ++len;
    }
    
    void addAtTail(int val) {
        if(head == 0) return addAtHead(val);
        
        ListNode *last = head;
        while(last->next) last = last->next;
        last->next = new ListNode(val);
        ++len;
    }
    
    void addAtIndex(int index, int val) {
        if(index > len) return;
        if(index == len) return addAtTail(val);
        if(index == 0) return addAtHead(val);
        
        ListNode *p = head;
        while(--index) p = p->next;
        p->next = new ListNode(val, p->next);
        ++len;
    }
    
    void deleteAtIndex(int index) {
        if(len <= 0 || index >= len) return;
        
        ListNode *p = head;
        if(index == 0) {
            head = head->next;
            --len;
            p->next = nullptr;
            delete p;
            return;
        }
        
        while(--index) p = p->next;
        ListNode *temp = p->next;
        p->next = temp->next;
        --len;
        temp->next = nullptr;
        delete temp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
