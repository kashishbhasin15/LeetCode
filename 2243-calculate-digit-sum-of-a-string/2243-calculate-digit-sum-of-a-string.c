#include<string.h>
char* digitSum(char* s, int k) 
{
 while(strlen(s)>k)
 {
    int n=strlen(s);
    char *str=malloc(n*3+1);
    int l=0;
    for(int i=0;i<n;i+=k)
    {
        int sum=0;
        for (int j=i;j<i+k && j<n;j++)
        {
            sum+=s[j]-'0';
        }
        l+=sprintf(str+l,"%d",sum);
    }

    str[l]='\0';
    s=str;
 }
 return s;
}