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
    void Reverse(ListNode*start,ListNode*end)
    {
        ListNode*prev=NULL;
        ListNode*curr=start;
        ListNode*endNext=end->next;
        while(curr!=endNext)
        {
            ListNode*nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left==right)return head;
        
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*temp=dummy;
        for(int i=1;i<left;i++)
        {
            temp=temp->next;
        }

        ListNode*start=temp->next;

        ListNode*end=start;
        for(int i=left;i<right;i++)
        {
            end=end->next;
        }
        
        ListNode*temp1=end->next;

        Reverse(start,end);

        temp->next=end;
        start->next=temp1;

        return dummy->next;
    }
};