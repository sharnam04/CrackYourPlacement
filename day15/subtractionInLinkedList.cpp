Node* reverseList(Node* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        Node*newhead=reverseList(head->next);
        Node*last=head->next;
        last->next=head;
        head->next=NULL;
        return newhead;
    }
    Node*func(Node*head1,Node*head2)
    {
        Node*list1=reverseList(head1);
        Node*ans=list1;
        Node*list2=reverseList(head2);
        
        int carry=0;
        while(list2)
        {
            int x=list1->data-carry;
            int y=list2->data;
            
            if(x>=y){
                list1->data=x-y;
                carry=0;
            }
            else
            {
                // if(x==0)
                carry=1;
                // else
                // {
                //  carry=carry-1;
                // }
                list1->data=10+x-y;
            }
            // cout<<list1->data<<endl;
            list1=list1->next;
            list2=list2->next;
        }
        while(list1 && carry)
        {
            int x=list1->data-carry;
            if(x<0){
                list1->data=10+x;
                carry=1;
                list1=list1->next;
            }
            else
            {
                list1->data-=carry;
                carry=0;
            }
        }
        
        return ans;
        
    }
    int length(Node*head)
    {
        if(head==NULL)return 0;
        int cnt=0;
        while(head)
        {
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
       while(head1!=NULL && head1->data==0)
       {
           head1=head1->next;
       }
       while(head2!=NULL && head2->data==0)
       {
           head2=head2->next;
       }
       if(head1==NULL && head2==NULL)return new Node(0);
       else if(head1==NULL)return head2;
       else if(head2==NULL)return head1;
       
       int l1=length(head1);
       int l2=length(head2);
       
       Node*ans=new Node(0);
       if(l1>l2)
       {
        ans=func(head1,head2);
       }
       else if(l1==l2)
       {
           Node*node1=head1;
           Node*node2=head2;
           while( node1 && node1->data==node2->data)
           {
               node1=node1->next;
               node2=node2->next;
           }
           if(!node1)return new Node(0);
           if(node1->data>node2->data)
           {
               ans=func(head1,head2);
           }
           else
           {
               ans=func(head2,head1);
           }
       }
       else if(l2>l1)
       {
           ans=func(head2,head1);
       }
       
    //   Node*temp=ans;
    //   while(temp){
    //       cout<<temp->data;
    //       temp=temp->next;
    //   }
    //   cout<<endl;
       Node* subll=reverseList(ans);
       while(subll!=NULL && subll->data==0)
       {
           subll=subll->next;
       }
       if(subll==NULL)return new Node(0);
       return subll;
    }