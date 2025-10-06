/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
    if((!head) || (!head->next))
    return;
    stack<ListNode*>st;
    ListNode* p=head;
    int sz=0;
    while(p!=NULL)
    {
      st.push(p);
      sz++;
      p=p->next;      
    }   
    ListNode* p1=head;
    for(int i=0;i<sz/2;i++)
    {
        ListNode* p2=st.top();
        st.pop();
        p2->next=p1->next;
        p1->next=p2;
        p1=p1->next->next;
    }
    p1->next=NULL;
    }
};