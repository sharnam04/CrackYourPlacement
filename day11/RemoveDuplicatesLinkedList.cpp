class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)return head;
        ListNode*temp=head;
        while(temp!=NULL || temp->next!=NULL)
        {

            if(temp->next->val==temp->val)
            {
                ListNode*temp2=temp->next->next;
                temp->next=temp2;
            }
            else
            temp=temp->next;
        }
        return head;
    }
};