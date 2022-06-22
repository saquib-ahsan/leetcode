class MyHashSet {
private:
    ListNode *head;
    
public:
    MyHashSet() {
        head = nullptr;
    }
    
    void add(int key) {
        if(contains(key)) return;
        
        if(!head) {
            head = new ListNode(key);
            return;
        }
        
        ListNode *tmp = new ListNode(key);
        tmp->next = head;
        head = tmp;
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        
        if(head->val == key) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = nullptr;
            delete tmp;
        } else {
            ListNode *tmp = head, *tmp_follower = nullptr;
            while(tmp->next) {
                tmp_follower = tmp;
                tmp = tmp->next;
                
                if(tmp->val == key) break;
            }
            
            tmp_follower->next = tmp->next;
            tmp->next = nullptr;
            delete tmp;
        }
    }
    
    bool contains(int key) {
        ListNode *tmp = head;
        while(tmp) {
            if(tmp->val == key) return true;
            tmp = tmp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
