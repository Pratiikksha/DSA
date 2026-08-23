struct Node{
    int key;
    int val;
    Node* next;

    Node(int k, int v, Node* l){
        key=k;
        val=v;
        next=l;
    }
};

const int mod=10007;
class MyHashMap {
public:
    vector<Node*>mp;
    MyHashMap() {
        mp.resize(mod,nullptr);
    }
    int hash(int k){
        return k%mod;
    }
    void put(int key, int value) {
        int h=hash(key);
         Node* head=mp[h];
          while(head) {
            if(head->key == key) {
                head->val = value;
                return;
            }
            head = head->next;
        }
        Node* node= new Node(key, value,mp[h]);
        mp[h]=node;
    }
    
    int get(int key) {
        int h= hash(key);
        if(mp[h]==nullptr) return -1;
        else {
            Node* head=mp[h];
            while(head){
                if(head->key==key){
                    return head->val;
                }
                head=head->next;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int h=hash(key);
        if(mp[h]==nullptr) return;
        else{
            Node* head=mp[h];
            if(head->key==key){
                mp[h]=head->next;
                delete head;
                return;
            }
            while(head->next){
                if(head->next->key==key)
                {
                    Node* temp=head->next;
                    head->next=head->next->next;
                    delete temp;
                    return;
                }
                head=head->next;
            }
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