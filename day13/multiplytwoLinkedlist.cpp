class solution {
  public:
    long long num(Node *first)
    {
        long long n=0;long long m=1e9+7;
        while(first!=NULL)
        {
            long long x=first->data;
            n=(n*10+x)%m;
            first=first->next;
        }
        return n;
    }
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long m=1e9+7;
        long long nums1=num(first);
        long long nums2=num(second);
        return (nums1*nums2)%m;
    }
};