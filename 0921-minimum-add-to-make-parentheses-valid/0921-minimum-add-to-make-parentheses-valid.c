int minAddToMakeValid(char* s) {

int startp=0;
int endp=0;
int star=0;
int temp;
for(int i=0;s[i]!='\0';i++)
{
    char ch=s[i];
    if(ch=='(')
    {
        startp++;
    }
    else if(ch=='*')
       star++;
    else if(ch==')')
    {
        if(startp>0)
        {
            startp--;
        }
        else
        {
            endp++;
        }
    }
    
    // if(startp>endp)
    // {
    //     temp=startp-endp;
    // }
    // else if(startp<endp)
    // {
    //     temp=endp-startp;
    // }
    // else
    //   temp=0;
}

  return startp+endp;
}