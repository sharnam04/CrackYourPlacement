/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode*head1=reverseList(l1);
        ListNode*head2=reverseList(l2);
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        int carry=0;

        while(head1 || head2 || carry)
        {
            int x=carry;
            if(head1){
                x+=head1->val;
                head1=head1->next;
            }
            if(head2){
                x+=head2->val;
                head2=head2->next;
            }
            carry=x/10;
            x=x%10;
           temp->next=new ListNode(x);
           temp=temp->next;
        }
        ListNode*ans=reverseList(dummy->next);
        return ans;
    }
};