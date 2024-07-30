class Solution {
public:
    int differenceLength(ListNode *headA,ListNode *headB)
    {
       int l1=0;
       int l2=0;
       ListNode *a=headA;ListNode *b=headB;
       while(a)
       {
        l1++;a=a->next;
       }
       while(b)
       {
        l2++;b=b->next;
       }
       return l1-l2;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff=differenceLength(headA,headB);

        if(diff<0)
        {
           while(diff++!=0)
           {
            headB=headB->next;
           }
        }
        else if(diff>0)
        {
           while(diff--!=0)
           {
            headA=headA->next;
           }
        }
        while(headA && headB)
        {
            if(headA==headB)return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};