#include<stdlib.h>

int compare(const void *a,const void *b)
{
    long long x=*(const int*)a;
    long long y=*(const int *)b;

    long long x1=x*x;
    long long x2=y*y;

    if(x1>x2)
       return 1;
    if(x1<x2)
       return -1;
    else
      return 0;
}

long long maxAlternatingSum(int* nums, int numsSize) {

    qsort(nums,numsSize,sizeof(int),compare);
    
// for (int i=0;i<numsSize-1;i++)
// {
//     for(int j=i;j<numsSize;j++)
//     {
//         long long a =nums[i];
//         long long b=nums[j];
//         if(a*a > b*b)
//         {
//             int temp=nums[i];
//             nums[i]=nums[j];
//             nums[j]=temp;
//         }
//     }
// }
    long long anns=0;

    for(int i=0;i<numsSize;i++)
    {
        long long x=nums[i];
        if(i<(numsSize)/2)
        {
            anns-=x*x;
        }
        else
        {
            anns+=x*x;
        }
    }

return anns;

}