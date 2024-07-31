/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node*lastofchild(Node*head)
    {
        while(head->next!=NULL)
        {
            head=head->next;
        }
        return head;
    }
    Node* flatten(Node* head) {
        if(head==NULL)return head;

        Node*temp=head;
        while(temp!=NULL)
        {
            if(temp->child)
            {
                Node*prevnext=temp->next;
                Node*last=lastofchild(temp->child);
                temp->next=temp->child;
                last->next=prevnext;
                if(prevnext)prevnext->prev=last;
                temp->child->prev=temp;
                temp->child=NULL;
            }
            temp=temp->next;
        }
        return head;

    }
};