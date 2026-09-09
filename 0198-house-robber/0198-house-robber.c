int rob(int* nums, int numsSize) {

// int sum=0;
// for(int i=0;i<numsSize;i++)
// {
//     if(i%2==0)
//     {
//         sum+=nums[i];
//     }
// }
// return sum;
if(numsSize==0)
  return 0;
if(numsSize==1)
   return nums[0];

int prev=0;
int curr=0;

for(int i=0;i<numsSize;i++)
{
    int temp=curr;
    if(prev+nums[i]>curr)
    {
        curr=prev+nums[i];
    }
    prev=temp;
}
return curr;
}