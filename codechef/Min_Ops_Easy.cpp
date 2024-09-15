#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to calculate the difference sum of the array
int differenceSum(const vector<int> &array)
{
    int diffSum = 0;
    for (int i = 1; i < array.size(); ++i)
    {
        diffSum += abs(array[i] - array[i - 1]);
    }
    return diffSum;
}

// Function to find minimum operations to satisfy the condition
int minOperations(vector<int> &array, int K)
{
    int n = array.size();
    int diffSum = differenceSum(array);

    if (diffSum <= K)
    {
        return 0;
    }

    int operations = 0;

    while (diffSum > K)
    {
        operations++;
        int maxDiffIndex = 1;
        int maxDiff = abs(array[1] - array[0]);

        // Find the segment with the maximum difference
        for (int i = 2; i < n; ++i)
        {
            int diff = abs(array[i] - array[i - 1]);
            if (diff > maxDiff)
            {
                maxDiff = diff;
                maxDiffIndex = i;
            }
        }

        // Apply the operation on the segment
        if (array[maxDiffIndex] > array[maxDiffIndex - 1])
        {
            array[maxDiffIndex]--;
        }
        else
        {
            array[maxDiffIndex]++;
        }

        // Recalculate the difference sum
        diffSum = differenceSum(array);
    }

    return operations;
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, Q;
        cin >> N >> Q;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        for (int q = 0; q < Q; ++q)
        {
            int L, R, K;
            cin >> L >> R >> K;

            // Extract subarray
            vector<int> subarray(A.begin() + L - 1, A.begin() + R);

            // Calculate minimum operations
            int result = minOperations(subarray, K);
            cout << result << endl;;
        }
     //   cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}
