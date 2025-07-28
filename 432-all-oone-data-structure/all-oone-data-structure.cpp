class AllOne {
public:
    struct Node
    {
        int count;
        list<string>keys;
        Node* prev;
        Node* next;
        Node(int c)
        {
            count =c;
            prev=NULL;
            next=NULL;
        }
    };
    unordered_map<string,Node*>mp;
    Node* head;
    Node* last;
    AllOne(){
    head=new Node(0);  
    last=head; 
    }
    
    Node* addnode(Node* prev,int count)
    {
        Node* newnode= new Node(count);
        newnode->next= prev->next;
        newnode->prev=prev;
        if(newnode->next!=NULL)
        {
           newnode->next->prev=newnode;
        }
        prev->next=newnode;
        if(prev==last)
        {
            last=newnode;
        }
        return newnode;
    }
    void removenode(Node* node)
    {
        node->prev->next=node->next;
        if(node->next!=NULL)
        {
            node->next->prev=node->prev;
        }
        if(last==node)
        {
            last=node->prev;
        } 
        delete node;
    }
    void inc(string key) {
    if(mp.find(key)==mp.end())
    {
      if(head->next==NULL || head->next->count!=1)
      {
         addnode(head,1);
      }
      head->next->keys.push_front(key);
      mp[key]=head->next;
    }
    else 
    {
        Node* currnode=mp[key];
        int currcount=currnode->count;
        if(currnode->next==NULL || currnode->next->count!=currcount+1)
        {
            addnode(currnode,currcount+1);
        }
        currnode->next->keys.push_front(key);
        mp[key]=currnode->next;
        currnode->keys.remove(key);
        if(currnode->keys.empty())
        {
            removenode(currnode);
        }
    }
    }  
    void dec(string key) {
    Node* currnode = mp[key];
    int currcount = currnode->count;
    if(currcount==1)
    {
        mp.erase(key);
    }else 
    {
       if(currnode->prev == head || currnode->prev->count != currcount - 1)
        {
            addnode(currnode->prev,currcount-1);
        }
        currnode->prev->keys.push_front(key);
        mp[key] = currnode->prev;
    }
    currnode->keys.remove(key);
    if(currnode->keys.empty())
    {
       removenode(currnode);
    }
    }
    
    string getMaxKey() {
    if(last==head)
    {
        return "";
    }    
    return last->keys.front();
    }
    string getMinKey() {
    if(head->next==NULL)
    {
        return "";
    }   
    return head->next->keys.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */