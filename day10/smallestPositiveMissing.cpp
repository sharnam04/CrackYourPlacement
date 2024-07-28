class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        int p=n-1;
        int i=0;
        while(i<n && i<=p)
        {
            if(arr[i]<=0)
            {
                swap(arr[i],arr[p]);
                p--;
            }
            else if(arr[i]>0)
            {
                i++;
            }
        }
         //marking arr[i] negative. 

        for(int i=0;i<=p;i++)
        {
          if(abs(arr[i])-1 < n  && arr[abs(arr[i])-1]>0)
          {
              arr[abs(arr[i])-1]= -arr[abs(arr[i])-1];
          }
        }
        for(int i=0;i<=p;i++)
        {
            if(arr[i]>0)return i+1;
        }
        return p+2;
    } 
};