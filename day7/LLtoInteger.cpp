public:
    int getDecimalValue(ListNode* head) {
       int ans=0;
       if(head==NULL)return ans;
       int len=length(head)-1;
       while(head!=NULL)
       {
          if(head->val)ans+=((head->val)*(1<<len));
          len--;
          head=head->next;
       }
       return ans;
    }
};