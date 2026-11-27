int maximumSaleItems(int** items, int itemsSize, int* itemsColSize, int budget) {
    int *add = (int*)calloc(itemsSize, sizeof(int));

    int minPrice = 1501;

    for (int i = 0; i < itemsSize; i++) {
        int factor = items[i][0];
        int price = items[i][1];

        if (price < minPrice) minPrice = price;

        for (int j = 0; j < itemsSize; j++) {
            if (i != j && items[j][0] % factor == 0) {
                add[i]++;
            }
        }
    }

    int *dp = (int*)calloc(budget + 1, sizeof(int));

    // 0/1 knapsack for first purchase of each type
    for (int i = 0; i < itemsSize; i++) {
        int cost = items[i][1];
        int value = 1 + add[i];

        for (int b = budget; b >= cost; b--) {
            if (dp[b - cost] + value > dp[b]) {
                dp[b] = dp[b - cost] + value;
            }
        }
    }

    int ans = 0;

    for (int spent = 0; spent <= budget; spent++) {
        int cur = dp[spent] + (budget - spent) / minPrice;
        if (cur > ans) ans = cur;
    }

    free(add);
    free(dp);

    return ans;
}