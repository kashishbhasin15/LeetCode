#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */

char *result[100000];
int resultSize = 0;

int leftRemove, rightRemove;


int isValid(char *s)
{
    int balance = 0;

    for(int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];

        if(ch == '(')
        {
            balance++;
        }
        else if(ch == ')')
        {
            balance--;

            if(balance < 0)
                return 0;
        }
    }

    return balance == 0;
}


int alreadyExists(char *s)
{
    for(int i = 0; i < resultSize; i++)
    {
        if(strcmp(result[i], s) == 0)
        {
            return 1;
        }
    }

    return 0;
}


void addResult(char *s)
{
    if(!alreadyExists(s))
    {
        result[resultSize] = malloc(strlen(s) + 1);
        strcpy(result[resultSize], s);
        resultSize++;
    }
}


void solve(char *s, int start, int leftRemove, int rightRemove)
{
    /*
        If we have removed all required
        parentheses, check validity.
    */
    if(leftRemove == 0 && rightRemove == 0)
    {
        if(isValid(s))
        {
            addResult(s);
        }

        return;
    }


    for(int i = start; s[i] != '\0'; i++)
    {
        char ch = s[i];

        /*
            Skip duplicate consecutive parentheses.

            Example:
            (())
             ↑ ↑

            Removing either identical '(' gives
            the same result.
        */
        if(i > start && s[i] == s[i - 1])
        {
            continue;
        }


        /*
            Remove '('
        */
        if(leftRemove > 0 && ch == '(')
        {
            char removed = s[i];

            /*
                Remove s[i] by shifting
                everything after it one position left.
            */
            memmove(
                &s[i],
                &s[i + 1],
                strlen(&s[i + 1]) + 1
            );

            /*
                Continue from i because a new character
                has now shifted into position i.
            */
            solve(
                s,
                i,
                leftRemove - 1,
                rightRemove
            );

            /*
                Restore the original string.
            */
            memmove(
                &s[i + 1],
                &s[i],
                strlen(&s[i]) + 1
            );

            s[i] = removed;
        }


        /*
            Remove ')'
        */
        if(rightRemove > 0 && ch == ')')
        {
            char removed = s[i];

            /*
                Remove s[i].
            */
            memmove(
                &s[i],
                &s[i + 1],
                strlen(&s[i + 1]) + 1
            );

            /*
                Continue from i.
            */
            solve(
                s,
                i,
                leftRemove,
                rightRemove - 1
            );

            /*
                Restore the original string.
            */
            memmove(
                &s[i + 1],
                &s[i],
                strlen(&s[i]) + 1
            );

            s[i] = removed;
        }
    }
}


char** removeInvalidParentheses(char* s, int* returnSize)
{
    int openStack[10000];
    int invalidClose[10000];

    int top = -1;
    int invalidCount = 0;


    /*
        STEP 1:
        Find unmatched ')' using stack.
    */

    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '(')
        {
            openStack[++top] = i;
        }
        else if(s[i] == ')')
        {
            if(top >= 0)
            {
                /*
                    '(' and ')' match.
                */
                top--;
            }
            else
            {
                /*
                    This ')' has no '(' before it.
                */
                invalidClose[invalidCount++] = i;
            }
        }
    }


    /*
        STEP 2:
        Any '(' remaining in the stack
        is unmatched.
    */

    leftRemove = top + 1;


    /*
        Number of unmatched ')' that must
        be removed.
    */

    rightRemove = invalidCount;


    /*
        STEP 3:
        Generate all possibilities.
    */

    resultSize = 0;

    solve(
        s,
        0,
        leftRemove,
        rightRemove
    );


    *returnSize = resultSize;

    return result;
}