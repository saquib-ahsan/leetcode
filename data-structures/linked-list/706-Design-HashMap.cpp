struct Node {
    int key, val;
    Node *next;
    // constructors
    Node() : key(0), val(0), next(nullptr) {}
    Node(int x, int y) : key(x), val(y), next(nullptr) {}
};

class MyHashMap {
private:
    Node *head;
    
public:
    MyHashMap() {
        head = nullptr;
    }
    
    void put(int key, int value) {
        if(!head) {
            head = new Node(key, value);
            return;
        }
        
        if(get(key) == -1) {
            Node *tmp = new Node(key, value);
            tmp->next = head;
            head = tmp;
        } else {
            Node *tmp = head;
            while(tmp->key != key) {
                tmp = tmp->next;
            }
            tmp->val = value;
        }
    }
    
    int get(int key) {
        Node *tmp = head;
        while(tmp) {
            if(tmp->key == key) return tmp->val;
            tmp = tmp->next;
        }
        return -1;
    }
    
    void remove(int key) {
        if(get(key) == -1) return;
        
        Node *tmp = head, *tmp_follower = nullptr;
        while(tmp->key != key) {
            tmp_follower = tmp;
            tmp = tmp->next;
        }
        
        if(!tmp_follower) {
            Node *a = head;
            head = head->next;
            a->next = nullptr;
            delete a;
        } else {
            tmp_follower->next = tmp->next;
            tmp->next = nullptr;
            delete tmp;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
