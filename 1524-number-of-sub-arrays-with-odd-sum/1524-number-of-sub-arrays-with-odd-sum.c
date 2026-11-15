
int numOfSubarrays(int* arr, int arrSize)
{
    long long odd = 0;
    long long even = 1;
    long long sum = 0;
    long long count = 0;
    int mod = 1000000007;

    for(int i = 0; i < arrSize; i++)
    {
        sum += arr[i];

        if(sum % 2 == 0)
        {
            count += odd;
            even++;
        }
        else
        {
            count += even;
            odd++;
        }

        count %= mod;
    }

    return count;
}
