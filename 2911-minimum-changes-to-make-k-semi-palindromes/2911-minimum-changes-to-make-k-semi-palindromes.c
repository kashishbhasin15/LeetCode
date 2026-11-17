
#include <stdio.h>
#include <string.h>
#include <limits.h>

int minimumChanges(char* s, int k)
{
    int n = strlen(s);

    // Step 1: Precompute minimum changes for every substring
    int cost[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cost[i][j] = INT_MAX;
    }

    for (int l = 0; l < n; l++)
    {
        for (int r = l + 1; r < n; r++)
        {
            int len = r - l + 1;

            // Try every proper divisor of substring length
            for (int d = 1; d < len; d++)
            {
                if (len % d != 0)
                    continue;

                int changes = 0;

                // Check each group formed by positions
                // having the same remainder modulo d
                for (int rem = 0; rem < d; rem++)
                {
                    int left = rem;
                    int right = rem + ((len - 1 - rem) / d) * d;

                    while (left < right)
                    {
                        if (s[l + left] != s[l + right])
                            changes++;

                        left += d;
                        right -= d;
                    }
                }

                if (changes < cost[l][r])
                    cost[l][r] = changes;
            }
        }
    }

    // Step 2: DP to divide string into exactly k parts
    int dp[k + 1][n + 1];

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
            dp[i][j] = INT_MAX;
    }

    dp[0][0] = 0;

    for (int parts = 1; parts <= k; parts++)
    {
        for (int i = 2 * parts; i <= n; i++)
        {
            for (int j = 2 * (parts - 1); j <= i - 2; j++)
            {
                if (dp[parts - 1][j] == INT_MAX)
                    continue;

                int current = dp[parts - 1][j] + cost[j][i - 1];

                if (current < dp[parts][i])
                    dp[parts][i] = current;
            }
        }
    }

    return dp[k][n];
}
