
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int maxSelectedElements(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare);

    int dp[1000002] = {0};
    int ans = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int num = nums[i];

        dp[num + 1] = dp[num] + 1;

        dp[num] = dp[num - 1] + 1;

        if (dp[num] > ans)
        {
            ans = dp[num];
        }

        if (dp[num + 1] > ans)
        {
            ans = dp[num + 1];
        }
    }

    return ans;
}
