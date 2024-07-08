#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define nl cout << "\n"
#define dbg(var) cout << #var << "=" << var << " "
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())         // sort
#define mxe(v) *max_element(v.begin(), v.end()) // find max element in vector
#define mne(v) *min_element(v.begin(), v.end()) // find min element in vector
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed
#define bin(x, y) bitset<y>(x)
using namespace std;
int MOD = 1e9 + 7; // Hardcoded, directly change from here for functions!

void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }
// ================================== take ip/op like vector,pairs directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
// ===================================END Of the input module ==========================================
bool func(vector<string> &v, vector<string> &a, int n, int m)
{
    fr(i, n - 1)
    {
        fr(j, m - 1)
        {
            if (v[i][j] != a[i][j])
            {   int dif = ((a[i][j] - '0') - (v[i][j] - '0') + 3) % 3;
                if(dif == 1){
                    v[i][j] = (v[i][j] - '0' + 1) % 3 + '0';
                    v[i + 1][j] = (v[i + 1][j] - '0' + 2) % 3 + '0';
                    v[i][j + 1] = (v[i][j + 1] - '0' + 2) % 3 + '0';
                    v[i + 1][j + 1] = (v[i + 1][j + 1] - '0' + 1) % 3 + '0';
                }else{
                    v[i][j] = (v[i][j] - '0' + 2) % 3 + '0';
                    v[i + 1][j] = (v[i + 1][j] - '0' + 1) % 3 + '0';
                    v[i][j + 1] = (v[i][j + 1] - '0' + 1) % 3 + '0';
                    v[i + 1][j + 1] = (v[i + 1][j + 1] - '0' + 2) % 3 + '0';
                }
            }
        }
    }
    return v == a;
}

void solve()
{
    int n = 1, m;
    cin >> n >> m;
    vector<string> v(n), a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (func(v, a, n, m))
    {
        cout << "YES";
        nl;
    }
    else
    {
        cout << "NO";
        nl;
    }
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
