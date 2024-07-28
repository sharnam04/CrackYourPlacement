 sort(b,b+n);
        sort(a,a+n);
        int i=0;int j=n-1;
        while(i<n && j>=0)
        {
            if(a[i]<k-b[j])return false;
            i++;j--;
        }
        return true;