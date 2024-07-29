class Solution
{
    
    public:
    
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
    
    Node *compute(Node *head)
    {
        // your code goes here
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        //REVERSE THE LINKED LIST
        Node *temphead=reverseList(head);
        //DELETE SMALL ELEMENTS
        Node *temp2=temphead;int maxi=temp2->data;
        while(temp2!=NULL && temp2->next!=NULL)
        {
            
            if(temp2->next->data>=maxi)
            {
                maxi=temp2->next->data;
                temp2=temp2->next;
            }
            else
            {
                temp2->next=temp2->next->next;
            }
        }
        // REVERSE THE LIST
        Node*ans=reverseList(temphead);
        return ans;
    }
    
};