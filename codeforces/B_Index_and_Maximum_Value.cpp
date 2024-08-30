#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int n, m; // Length of the array and number of operations
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i]; // Input initial array
        }

        int maxi = *max_element(a.begin(), a.end()); // Find the maximum value in the array
        int add = 0;                                        // Tracks net effect of '+' operations
        int subtract = 0;                                   // Tracks net effect of '-' operations

        for (int i = 0; i < m; ++i)
        {
            char c;   // Operation type ('+' or '-')
            int l, r; // Range [l, r]
            cin >> c >> l >> r;

            if (c == '+')
            {
                add++; // Increment the net addition effect
            }
            else
            {
                subtract++; // Increment the net subtraction effect
            }

            // Calculate the current maximum value after applying all effects
            int current_max = maxi + add - subtract;
            cout << current_max << " "; // Output the maximum value after this operation
        }

        cout << endl; // Newline for the next test case output
    }

    return 0;
}
