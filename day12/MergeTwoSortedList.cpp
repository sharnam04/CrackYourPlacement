class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 || !list2)
        {
            return (!list2 ? list1 : list2);
        }

        ListNode*node=new ListNode();
        if(list1->val>list2->val)
        {
            node->next=list2;
            list2=list2->next;
        }
        else
        {
            node->next=list1;
            list1=list1->next;
        }
        node->next->next=mergeTwoLists(list1,list2);
        return node->next;
    }
};