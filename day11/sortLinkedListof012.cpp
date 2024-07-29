class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        if(head==NULL || head->next==NULL)return head;
        int cnt0=0,cnt1=0,cnt2=0;
        Node*temp=head;
        while(temp!=NULL)
        {
            if(temp->data==0)cnt0++;
            if(temp->data==1)cnt1++;
            if(temp->data==2)cnt2++;
            temp=temp->next;
        }
            temp=head;
            while(cnt0)
            {
             temp->data=0;
             cnt0--;
             temp=temp->next;
            }
            while(cnt1)
            {
              temp->data=1;
             cnt1--;
             temp=temp->next;
            }
            while(cnt2)
            {
              temp->data=2;
             cnt2--;
             temp=temp->next;
            }
            return head;
        
    }
};