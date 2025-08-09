struct Node{
    int data;
    Node* next;

    Node(int key)
    {
        data=key;
        next=nullptr;
    }
};

class MyLinkedList {
private:
    Node* dummy, *head, *tail;
    int size;
public:

    MyLinkedList() {
        dummy=new Node(-1);
        head=nullptr;
        tail=nullptr;
        size=0;
    }
    
    int get(int index) {
        Node* curr=dummy->next;

        for(int i=0; i<=index && curr; i++)
        {
            if(i==index)
            {
                return curr->data;
            }

            curr=curr->next;
        }

        return -1;
    }
    
    void addAtHead(int val) {
        Node* temp=dummy->next;
        dummy->next=new Node(val);
        dummy->next->next=temp;

        if(!head)
        {
            tail=dummy->next;
        }

        head=dummy->next;

        size++;
    }
    
    void addAtTail(int val) {
        if(!tail)
        {
            addAtHead(val);
            return;
        }

        tail->next=new Node(val);
        tail=tail->next;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size)
        {
            return;
        }

        Node* curr=dummy;

        for(int i=0; i<index && curr->next; i++)
        {
            curr=curr->next;
        }

        Node* newNode=new Node(val);
        newNode->next=curr->next;
        curr->next=newNode;

        if(!newNode->next)
        {
            tail=newNode;
        }

        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size) 
        {
            return;
        }

        Node* curr=dummy;

        for(int i=0; i<index && curr->next; i++)
        {
            curr=curr->next;
        }

        Node* temp=curr->next;
        curr->next=temp->next;

        if(index==size-1) 
        {
            tail=curr;
        }

        delete temp;
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