#include <limits.h>

int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
    int minSum = INT_MAX;

    for (int i = 0; i < numsSize; i++) 
    {
        int sum = 0;

        for (int j = i; j < numsSize; j++) 
        {
            sum += nums[j];

            int length = j - i + 1;

            if (length >= l && length <= r && sum > 0) 
            {
                if (sum < minSum) 
                {
                    minSum = sum;
                }
            }

            if (length == r) 
            {
                break;
            }
        }
    }

    if (minSum == INT_MAX) 
    {
        return -1;
    }

    return minSum;
}