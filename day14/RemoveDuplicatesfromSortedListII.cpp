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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL ||head->next==NULL)return head;

        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*temp=dummy;
        while(temp!=NULL && temp->next!=NULL)
        {
            int x=temp->next->val;
            ListNode*temp2=temp->next;int cnt=0;
            while(temp2->next && temp2->next->val==x)
            {
                cnt++;
                temp2=temp2->next;
            }
            if(cnt)
            {
                temp->next=temp2->next;
            }
            else
            {
                temp=temp->next;
            }
        }
        return dummy->next;
    }
};