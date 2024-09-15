#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to solve a single test case
void solve()
{
    int l, n, m;
    cin >> l >> n >> m;

    vector<int> a(l);
    unordered_map<int, vector<pair<int, int>>> pos; // stores positions of matrix elements

    for (int i = 0; i < l; ++i)
    {
        cin >> a[i];
    }

    // Reading the matrix and storing the positions of each element
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int val;
            cin >> val;
            pos[val].emplace_back(i, j); // store the position of the value in the matrix
        }
    }

    // Starting the game with Tsovak
    bool isTsovakTurn = true;
    int lastRow = -1, lastCol = -1; // Start outside the matrix

    for (int i = 0; i < l; ++i)
    {
        int currentValue = a[i];
        bool canMove = false;

        // Checking if we can find the current element in the allowed submatrix
        for (auto &p : pos[currentValue])
        {
            int r = p.first, c = p.second;
            if (r > lastRow && c > lastCol)
            { // Check if the position is valid
                lastRow = r;
                lastCol = c;
                canMove = true;
                break;
            }
        }

        // If the player cannot move, the game ends and the other player wins
        if (!canMove)
        {
            if (isTsovakTurn)
            {
                cout << "N" << endl; // Narek wins
            }
            else
            {
                cout << "T" << endl; // Tsovak wins
            }
            return;
        }
    }

    // If all elements are found, the last player to move loses
    if (!isTsovakTurn)
    {
        cout << "N" << endl; // Narek wins
    }
    else
    {
        cout << "T" << endl; // Tsovak wins
    }
}

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
