class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode*newhead=reverseList(head->next);
        ListNode*last=head->next;
        last->next=head;
        head->next=NULL;
        return newhead;
    }
};