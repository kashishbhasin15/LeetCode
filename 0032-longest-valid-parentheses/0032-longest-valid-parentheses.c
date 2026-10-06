int longestValidParentheses(char* s) {
    int top=-1;
    top++;
    int stack[100000];
    stack[top]=-1;
    int max=0;

    for(int i=0;s[i]!='\0';i++)
    {
        char ch=s[i];
        if(ch=='(')
        {
            top++;
            stack[top]=i;
        }
        else
        {
            top--;
            if(top==-1)
            {
                stack[++top]=i;
            }
            else
            {
                int len=i-stack[top];
                if(len>max)
                {
                    max=len;
                }   
            }
        }
    }
    return max;
}