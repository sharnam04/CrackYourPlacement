class Solution {
private:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* merge(ListNode* node1, ListNode* node2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(node1 != NULL && node2 != NULL){
            if(node1-> val < node2-> val){
                temp -> next = node1;
                temp = node1;
                node1 = node1-> next;
            }
            else{
                temp -> next = node2;
                temp = node2;
                node2 = node2-> next;
            }
        }

        if(node1) temp -> next = node1;
        else temp -> next = node2;

        ListNode* mergedHead = dummyNode->next;
        delete dummyNode; // Free up memory allocated for dummy node
        return mergedHead;
    }

public:
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head -> next == NULL) return head;

        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = NULL;

        ListNode* leftHead = sortList(left);
        ListNode* rightHead = sortList(right);
        ListNode* mergedHead = merge(leftHead, rightHead);

        return mergedHead;

    }
};