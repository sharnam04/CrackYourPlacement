class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int cnt=0;
       ListNode*fast=head;
       ListNode*slow=head;
       while(cnt!=n && fast!=NULL)
       {
         fast=fast->next;
         cnt++;
       }
       if(fast==NULL)return slow->next;

       while(fast!=NULL && fast->next!=NULL)
       {
          slow=slow->next;
          fast=fast->next;
       }
    
        slow->next=slow->next->next;
        return head;
    }
};