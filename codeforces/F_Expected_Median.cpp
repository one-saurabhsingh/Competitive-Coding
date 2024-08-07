#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

// Function to compute x^y % MOD using iterative method
long long power(long long x, long long y)
{
    long long result = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y % 2 == 1)
            result = (result * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return result;
}

// Function to precompute factorials and inverse factorials
void precompute_factorials(vector<long long> &fact, vector<long long> &invFact, int maxN)
{
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= maxN; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[maxN] = power(fact[maxN], MOD - 2);
    for (int i = maxN - 1; i > 0; i--)
    {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}

// Function to compute nCk % MOD
long long comb(int n, int k, const vector<long long> &fact, const vector<long long> &invFact)
{
    if (k > n || k < 0)
        return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int main()
{
    int t;
    cin >> t;

    vector<long long> fact(200001), invFact(200001);
    precompute_factorials(fact, invFact, 200000);

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long sum = 0;
        int median_pos = (k + 1) / 2 - 1; // Median position in the sorted subsequence

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                long long count_left = comb(i, median_pos, fact, invFact);
                long long count_right = comb(n - i - 1, k - median_pos - 1, fact, invFact);
                long long total_count = count_left * count_right % MOD;
                sum = (sum + total_count) % MOD;
            }
        }

        cout << sum << endl;
    }

    return 0;
}
