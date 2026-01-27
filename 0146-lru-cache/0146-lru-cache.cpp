class LRUCache {
public:
    class node {
        public:
           int key;
           int val;
           node* next;
           node* prev;
           node(int _key, int _val) {
               key=_key;
               val=_val;
           }
    };
    
    int cap;
    unordered_map<int, node*> mp;

    node* head=new node(-1, -1);
    node* tail=new node(-1, -1);

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addnode(node* newNode) {
        node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        temp->prev=newNode;
        head->next=newNode;
    }

    void deletenode(node* delnode) {
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delnext->prev=delprev;
        delprev->next=delnext;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()) {
            node* resnode=mp[key];
            int ans=resnode->val;
            deletenode(resnode);
            addnode(resnode);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()) {
            node* resnode=mp[key];
            mp.erase(key);
            deletenode(resnode);
        }
        if(mp.size()==cap) {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */