#include <bits/stdc++.h>
using namespace std;
#define int long long

int countGoodSubsequences(const vector<int> &A)
{
    int N = A.size();
    int goodCount = 0;

    for (int mask = 0; mask < (1 << N); ++mask)
    {
        if (__builtin_popcount(mask) < 2)
            continue;

        vector<int> subsequence;
        for (int i = 0; i < N; ++i)
        {
            if (mask & (1 << i))
            {
                subsequence.push_back(A[i]);
            }
        }

        if (subsequence.size() < 2)
            continue;

        int maxElem = *max_element(subsequence.begin(), subsequence.end());
        int minElem = *min_element(subsequence.begin(), subsequence.end());
        int subsequenceLength = subsequence.size();

        if (maxElem - minElem == subsequenceLength)
        {
            ++goodCount;
        }
    }

    return goodCount;
}

int32_t main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }

        int result = countGoodSubsequences(A);
        cout << result << endl;
    }

    return 0;
}