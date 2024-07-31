class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        if (!head || !head->next) {
            return head;
        }
        Node* odd =new Node(0); 
        Node* even = new Node(0);
        
        Node* oddhead = odd;Node* evenhead = even;

        while (head!=NULL) 
        {
            if(head->data%2==0)
            {
                even->next=head;
                even=even->next;
            }
            else
            {
                odd->next=head;
                odd=odd->next;
            }
            head=head->next;
        }
        even->next = oddhead->next;
        odd->next=NULL;
        return evenhead->next;
    }
};