class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        ListNode*curr=head;
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->next;
        }
        int k=st.size()/2;
        curr=head;
        while(k--)
        {
            ListNode*currnext=curr->next;
            ListNode*node=st.top();
            curr->next=node;
            curr=currnext;
            node->next=currnext;
            st.pop();
        }
        curr->next=NULL;
    }
};