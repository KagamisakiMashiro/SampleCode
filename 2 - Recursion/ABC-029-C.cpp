#include <cstdio>
#include <string>
using namespace std;

void bruteForce(string prefix, int n)
{
    if (n == 1)
    {
        printf("%sa\n", prefix.c_str());
        printf("%sb\n", prefix.c_str());
        printf("%sc\n", prefix.c_str());
    }
    else
    {
        bruteForce(prefix + "a", n - 1);
        bruteForce(prefix + "b", n - 1);
        bruteForce(prefix + "c", n - 1);
    }
}

int main()
{
    int n;
    scanf("%d\n", &n);
    bruteForce("", n);
    return 0;
}
