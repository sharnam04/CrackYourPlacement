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
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)return true;

        ListNode*slow=head;
        ListNode*fast=head;
        while( fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*head2=reverseList(slow->next);
        // slow->next=head2;
        while(head && head2)
        {
            if(head->val!=head2->val)return false;

            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};