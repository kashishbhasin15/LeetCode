char* removeOuterParentheses(char* s) {
    char stack[100000];
    int top=-1;
    char *ans=malloc(strlen(s)+1);
    int j=0;

    for(int i=0;s[i]!='\0';i++)
    {
        char ch=s[i];
        if(ch=='(')
        {
            if(top!=-1)
            {
                ans[j++]=ch;
            }
            top++;
            stack[top]=ch;
        }
        else if(ch==')')
        {
            top--;
            if(top!=-1)
            {
                ans[j++]=ch;
            }
        }
    }
    ans[j]='\0';
    return ans;
}