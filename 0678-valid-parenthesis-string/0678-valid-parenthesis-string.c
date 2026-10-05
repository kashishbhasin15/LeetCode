int top = -1;
int startop = -1;

int stack[100000];
int star[100000];

int pop()
{
    if(top == -1)
        return -1;

    return stack[top--];
}

int starpop()
{
    if(startop == -1)
        return -1;

    return star[startop--];
}

void push(int index)
{
    stack[++top] = index;
}

void starpush(int index)
{
    star[++startop] = index;
}

bool checkValidString(char* s)
{
    // Reset global stacks
    top = -1;
    startop = -1;

    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '(')
        {
            push(i);
        }

        else if(s[i] == '*')
        {
            starpush(i);
        }

        else if(s[i] == ')')
        {
            // First priority: use '('
            if(top != -1)
            {
                pop();
            }

            // Otherwise use '*' as '('
            else if(startop != -1)
            {
                starpop();
            }

            // Nothing available
            else
            {
                return false;
            }
        }
    }

    // Match remaining '(' with '*' that occurs AFTER '('
    while(top != -1 && startop != -1)
    {
        if(stack[top] < star[startop])
        {
            pop();
            starpop();
        }
        else
        {
            return false;
        }
    }

    return top == -1;
}