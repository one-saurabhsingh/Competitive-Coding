#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minimum_possible_length(int N, string S)
{
    int back_count = 0, front_count = 0;
    // Count occurrences of "back"
    for (size_t pos = 0; pos <= S.size() - 4; pos++)
    {
        if (S.substr(pos, 4) == "back")
        {
            back_count++;
        }
    }
    // Count occurrences of "front"
    for (size_t pos = 0; pos <= S.size() - 5; pos++)
    {
        if (S.substr(pos, 5) == "front")
        {
            front_count++;
        }
    }
    // Minimum length after reductions
    int min_length = N - back_count * 3 - front_count * 4;
    return max(min_length, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    vector<int> results;

    while (T--)
    {
        int N;
        string S;
        cin >> N >> S;
        results.push_back(minimum_possible_length(N, S));
    }

    for (int result : results)
    {
        cout << result << "\n";
    }

    return 0;
}
