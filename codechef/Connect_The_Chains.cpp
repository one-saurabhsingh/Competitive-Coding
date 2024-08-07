#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll solve(int N, int M, vector<vector<ll>> &chains)
{
    vector<ll> maxPrefix(N, 0);
    vector<ll> maxSuffix(N, 0);
    vector<ll> chainSum(N, 0);
    ll totalSum = 0;

    for (int i = 0; i < N; i++)
    {
        ll prefix = 0;
        ll suffix = 0;
        for (int j = 0; j < M; j++)
        {
            prefix += chains[i][j];
            suffix += chains[i][M - 1 - j];
            maxPrefix[i] = max(maxPrefix[i], prefix);
            maxSuffix[i] = max(maxSuffix[i], suffix);
            chainSum[i] += chains[i][j];
        }
        totalSum += chainSum[i];
    }

    ll maxDiameter = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            maxDiameter = max(maxDiameter, maxSuffix[i] + maxSuffix[j]);
            maxDiameter = max(maxDiameter, maxPrefix[i] + maxPrefix[j]);
        }
        maxDiameter = max(maxDiameter, chainSum[i]);
    }

    return max(maxDiameter, totalSum - *min_element(chainSum.begin(), chainSum.end()));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        vector<vector<ll>> chains(N, vector<ll>(M));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> chains[i][j];
            }
        }

        cout << solve(N, M, chains) << "\n";
    }

    return 0;
}