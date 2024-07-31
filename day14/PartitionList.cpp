
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL)return head;
        ListNode*smallHead=new ListNode(0);
        ListNode*largeHead=new ListNode(0);
        ListNode*t1=smallHead;ListNode*t2=largeHead;
        while(head!=NULL)
        {
            if(head->val<x)
            {
                t1->next=head;
                t1=t1->next;
            }
            else
            {
                t2->next=head;
                t2=t2->next;
            }
            head=head->next;
        }
        t1->next=largeHead->next;
        t2->next=NULL;
        return smallHead->next;
    }
};