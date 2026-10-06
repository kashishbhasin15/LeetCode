int scoreOfParentheses(char* s) {
    int top=-1,star=0;
    int score=0;
    int stack[10000000];
    // stack[0]=0;

    for(int i=0;s[i]!='\0';i++)
    {
        char ch=s[i];
        if(ch=='(')
        {
            stack[++top]=score;
            score=0;
        }
        else if(ch=='*')
        {
            star++;
        }
        else if(ch==')')
        {
            if(score==0)
                score=1;
            else 
              score=2*score;
            
            score+=stack[top];
            top--;
        }
    }
    return score;
}