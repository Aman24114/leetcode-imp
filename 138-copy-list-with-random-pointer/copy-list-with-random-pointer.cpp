/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    void f1(Node* head)
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* nxtele=temp->next;
            Node* copy = new Node(temp->val);
            temp->next=copy; 
            copy->next=nxtele;
            temp=nxtele;
        }
    }
    void f2(Node* head)
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* copy=temp->next;
            if(temp->random)
            {
                copy->random = temp->random->next; 
            }
            else 
            {
                copy->random=NULL;
            }
            temp=temp->next->next;
        }
    }
    Node* f3(Node* head)
    {
        Node* temp=head;
        Node* dummy=new Node(-1);
        Node* res=dummy;
        while(temp!=NULL)
        {
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head){
    if(!head)
    return NULL;
    f1(head);
    f2 (head);
    return f3(head);
    }
};