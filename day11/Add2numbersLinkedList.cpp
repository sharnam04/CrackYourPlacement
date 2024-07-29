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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        int carry=0;
        ListNode*head=new ListNode();
        ListNode*temp=head;
        while(l1 || l2 || carry)
        {
            int x=carry;
            if(l1)
            {
                x+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                x+=l2->val;
                l2=l2->next;
            }
            int value=x%10;
            carry=x/10;
            temp->next=new ListNode(value);
            temp=temp->next;
        }
        return head->next;
        
         
    }
};