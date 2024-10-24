#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define double long double
#define ve vector
const int K = 998244353;
#define fr(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define rfr(i, a, b) for (int i = a; i >= b; i--)
const int inf = 1e18;
const int N = 1e7 + 10;
vector<bool> isPrime;
vector<int> hiprime;
vector<int> loprime;
#define in3(a, b, c) \
    int a, b, c;     \
    cin >> a >> b >> c
#define in4(a, b, c, d) \
    int a, b, c, d;     \
    cin >> a >> b >> c >> d
#define in5(a, b, c, d, e) \
    int a, b, c, d, e;     \
    cin >> a >> b >> c >> d >> e
#define in6(a, b, c, d, e, f) \
    int a, b, c, d, e, f;     \
    cin >> a >> b >> c >> d >> e >> f
#define tt    \
    int t;    \
    cin >> t; \
    while (t--)
#define in(x) \
    int x;    \
    cin >> x;
#define in2(a, b) \
    int a, b;     \
    cin >> a >> b
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define is(s) \
    string s; \
    cin >> s
#define endl '\n'
#define sync                               \
    {                                      \
        ios_base ::sync_with_stdio(false); \
        cin.tie(NULL);                     \
        cout.tie(NULL);                    \
    }

// MEX
int findmex(vector<int> v)
{
    set<int> s;
    fr(i, 0, v.size()) { s.insert(v[i]); }
    int MEX{}, i{};
    for (auto j : s)
    {
        if (j != i)
            break;
        else
            i++;
    }
    MEX = i;
    return MEX;
}

signed main()
{
    sync;
    tt
    {
        in2(n, k);
        ve<int> a(n);
        fr(i, 0, n) cin >> a[i];

        ve<int> pref(n + 1);
        int sum = 0;
        sort(all(a));
        pref[0] = 0;

        fr(i, 1, n + 1)
        {
            pref[i] = a[i - 1] + pref[i - 1];
        }
        int ans = 0;
        int x = INT_MIN;

        fr(i, 0, n)
        {
            if ((sum + (a[i]) * (n - i)) >= k)
            {
                ans = sum + k;
                break;
            }
            sum++;
        }
        cout << ans << endl;
    }
}

B