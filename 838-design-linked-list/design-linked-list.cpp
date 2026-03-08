class MyLinkedList {
public: 
    class Node{
    public:
        int val;
        Node* next;
        Node(int n){
            val=n;
            next=NULL;
        }
    };
    Node* head;
    int size;
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    int get(int index) {
       if(index<0 || index>=size) return -1;
       Node* cur=head;
       for(int i=0;i<index;i++){
        cur=cur->next;
       } 
       return cur->val;
    }
    
    void addAtHead(int val) {
        Node* node= new Node(val);
        node->next=head;
        head=node;
        size++;
    }
    
    void addAtTail(int val) {
        Node* node= new Node(val);
        if(head==NULL)
           head=node;
        else{
            Node* cur=head;
            while(cur->next!=NULL){
                cur=cur->next;
            }
            cur->next=node;
        }
        size++;

    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return;
        if(index==0){
            addAtHead(val);
            return;
        }
        Node* node=new Node(val);
        Node* cur=head;
        for(int i=0;i<index-1;i++){
            cur=cur->next;
        }
        node->next=cur->next;
        cur->next=node;
        size++;
        
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size) return;
        if(index==0){
            if(head!=NULL)
               head=head->next;
        }
        else{
            Node* cur=head;
            for(int i=0;i<index-1;i++){
                cur=cur->next;
            }
            if(cur->next!=NULL)
               cur->next=cur->next->next;
        }
        size--;
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