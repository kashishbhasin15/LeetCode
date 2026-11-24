long long gcd(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int maxLength(int* nums, int numsSize) {
    long long mx = 0;
    long long ml = 1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > mx) mx = nums[i];
        ml = lcm(ml, nums[i]);
    }

    long long limit = ml * mx;
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        long long prod = 1;
        long long g = 0;
        long long l = 1;

        for (int j = i; j < numsSize; j++) {

            if (prod > limit / nums[j])
                break;

            prod *= nums[j];
            g = gcd(g, nums[j]);
            l = lcm(l, nums[j]);

            if (prod == g * l) {
                int len = j - i + 1;
                if (len > ans) ans = len;
            }

            if (prod > limit)
                break;
        }
    }

    return ans;
}