#include <cstdio>
#include <algorithm>
using namespace std;

long long int h[100000], s[100000];

bool checkSuccess(long long int n, long long int score)
{
    long long int maxAcceptTime[100000];
    for (long long int i = 0; i < n; ++i)
    {
        if (score - h[i] < 0)
        {
            return false;
        }
        maxAcceptTime[i] = (score - h[i]) / s[i];
    }
    sort(maxAcceptTime, maxAcceptTime + n);
    for (long long int i = 0; i < n; ++i)
    {
        if (maxAcceptTime[i] < i)
        {
            return false;
        }
    }
    return true;
}

long long int bs(long long int n, long long int minValue, long long int maxValue)
{
    long long int mean;
    while (minValue + 1 < maxValue)
    {
        mean = (minValue + maxValue) / 2;
        if (checkSuccess(n, mean))
        {
            maxValue = mean;
        }
        else
        {
            minValue = mean;
        }
    }
    return maxValue;
}

int main()
{
    long long int n;
    long long int maxValue = 0;
    scanf("%lld", &n);
    for (long long int i = 0; i < n; ++i)
    {
        scanf("%lld %lld", &h[i], &s[i]);
        long long int temp = h[i] + s[i] * n;
        if (temp > maxValue)
        {
            maxValue = temp;
        }
    }
    printf("%lld\n", bs(n, 0, maxValue));
    return 0;
}
