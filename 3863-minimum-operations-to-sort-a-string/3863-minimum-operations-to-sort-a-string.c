int minOperations(char* s) {
    
    int n=strlen(s);
    int i,sorted=1;
    char min=s[0],max=s[0];

    for(i=1;i<n;i++)
    {
        if(s[i-1]>s[i])
        {
            sorted =0;
            break;
        }
    }

    if(sorted==1)
       return 0;

    if(n==2)
       return -1;

    for(i=1;i<n;i++)
    {
        if(s[i]<min)
            min=s[i];
        if(s[i]>max)
           max=s[i];
    }
    if(s[0]==min||s[n-1]==max)
        return 1;

    for(i=1;i<n-1;i++)
    {
        if(s[i]==min || s[i]==max)
            return 2;
    }
    
    return 3;
}