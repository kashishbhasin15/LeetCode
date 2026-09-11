int searchInsert(int* nums, int numsSize, int target) {
int mid;    
int low=0,high=numsSize-1;
while(low<=high)
{
    mid=(low+high)/2;
    if(nums[mid]==target)
       return mid;
    else if(nums[mid]<target)
        low=mid+1;
    else
        high=mid-1;
}
// if(target<nums[0])
// {
//     return mid;
// }
return low;
}