Node *merge(Node *head1,Node *head2)
    {
        Node *dummy=new Node(-1);
        Node *temp=dummy;
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->data<head2->data)
            {
                temp->bottom=head1;
                temp=head1;
                head1=head1->bottom;
            }
            else 
            {
                temp->bottom=head2;
                temp=head2;
                head2=head2->bottom;
            }
            temp->next=NULL;
        }
        
        if(head1)temp->bottom=head1;
        else temp->bottom=head2;
        
        return dummy->bottom;
    }
    
    Node *flatten(Node *root) {
        // Your code here
        if(root==NULL || root->next==NULL)return root; 
        Node *mergehead=flatten(root->next);
        return merge(root,mergehead);
    }