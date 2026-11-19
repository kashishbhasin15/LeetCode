int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int minimizeSum(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare);

    int a = nums[numsSize - 1] - nums[2];

    int b = nums[numsSize - 2] - nums[1];

    int c = nums[numsSize - 3] - nums[0];

    int ans = a;

    if(b < ans)
        ans = b;

    if(c < ans)
        ans = c;

    return ans;
}