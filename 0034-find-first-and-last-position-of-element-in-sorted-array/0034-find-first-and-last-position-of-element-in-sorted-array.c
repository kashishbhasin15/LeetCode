/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
    int low=0;
    int high=numsSize-1;
    int *output = malloc(2 * sizeof(int));
    *returnSize=2;
    output[0]=-1;
    output[1]=-1;
    

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            output[0]=mid;
            high=mid-1;
        }
        else if(nums[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    
    low=0;
    high=numsSize-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            output[1]=mid;
            low=mid+1;
        }
        else if(nums[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    return output;
}