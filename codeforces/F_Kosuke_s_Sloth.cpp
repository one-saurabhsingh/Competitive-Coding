#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

const int MOD = 1000000007;
const int MAX_K = 100000;

struct PrecomputedData
{
    int period;
    int count;
    std::vector<int> positions;

    PrecomputedData() : period(0), count(0), positions() {}
};

int main()
{
    int t;
    std::cin >> t; // Number of test cases
    std::vector<std::pair<int, int>> test_cases;
    std::set<int> unique_k_set;

    // Read test cases and find unique k values
    for (int i = 0; i < t; ++i)
    {
        int n, k;
        std::cin >> n >> k;
        test_cases.emplace_back(n, k);
        unique_k_set.insert(k);
    }

    std::vector<int> unique_ks(unique_k_set.begin(), unique_k_set.end());

    std::vector<PrecomputedData> precomputed(MAX_K + 1);

    // Precompute for all unique k values
    for (int k : unique_ks)
    {
        if (k == 1)
        {
            continue;
        }

        int f_prev = 1 % k;
        int f_curr = 1 % k;
        int pos = 2;
        std::vector<int> positions;
        int max_iterations = 6 * k + 10;
        bool period_found = false;

        for (int i = 0; i < max_iterations; ++i)
        {
            int f_next = (f_prev + f_curr) % k;
            ++pos;
            if (f_next == 0)
            {
                positions.push_back(pos);
            }
            f_prev = f_curr;
            f_curr = f_next;

            if (f_prev == 1 && f_curr == 1)
            {
                precomputed[k].period = pos - 2;
                precomputed[k].count = positions.size();
                precomputed[k].positions = positions;
                period_found = true;
                break;
            }
        }

        if (!period_found)
        {
            precomputed[k].period = pos - 2;
            precomputed[k].count = positions.size();
            precomputed[k].positions = positions;
        }
    }

    // Process each test case
    std::vector<long long> results;
    for (const auto &[n, k] : test_cases)
    {
        if (k == 1)
        {
            results.push_back(n % MOD);
            continue;
        }

        const PrecomputedData &data = precomputed[k];
        int P = data.period;
        int C = data.count;
        const std::vector<int> &positions = data.positions;

        long long q = (n - 1) / C;
        long long r = (n - 1) % C;

        long long G = (q % MOD) * (P % MOD) % MOD;
        G = (G + (positions[r] % MOD)) % MOD;

        results.push_back(G);
    }

    // Output all results at once
    for (long long result : results)
    {
        std::cout << result << "\n";
    }

    return 0;
}
