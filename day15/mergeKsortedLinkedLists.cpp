class Solution {
public:
    ListNode*merge(ListNode*head1,ListNode*head2)
    {
       if(head1==NULL)return head2;
       if(head2==NULL)return head1;

       ListNode*dummy=new ListNode(0);
       ListNode*node=dummy;
       while(head1 && head2)
       {
         if(head1->val<head2->val)
         {
            node->next=head1;
            node=head1;
            head1=head1->next;
         }
         else
         {
            node->next=head2;
            node=head2;
            head2=head2->next;
         }
       }
       if(head1!=NULL)node->next=head1;
       else node->next=head2;
       return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        if(size==0)return NULL;
        // ListNode*dummy=new ListNode(0);
        ListNode*temp=new ListNode(0); 
        ListNode*t1=lists[0]; 
        for(int i=1;i<size;i++)
        {
            temp->next=merge(t1,lists[i]);
            t1=temp->next;
        }
        return t1;
    }
};