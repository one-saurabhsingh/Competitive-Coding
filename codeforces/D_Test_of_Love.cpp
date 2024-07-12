#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================
bool cross(int n, int m, int k, string& s){
    vi vis(n+2, false);
    queue<pair<int, int>> q;

    q.push(make_pair(0, 0));
    vis[0] = true;

    while (!q.empty())
    {
        pair<int, int> cu = q.front();
        int pos = cu.first;
        int sw = cu.second;
        q.pop();

        if (pos == n + 1)
        {
            return true;
        }
        rep(i,1,m)
        {
            int nPos = pos + i;
            if (nPos <= n + 1 && !vis[nPos])
            {
                if (nPos == n + 1 || s[nPos - 1] == 'L')
                {
                    vis[nPos] = true;
                    q.push(make_pair(nPos, sw));
                }
                else if (s[nPos - 1] == 'W' && sw < k)
                {
                    vis[nPos] = true;
                    q.push(make_pair(nPos, sw + 1));
                }
            }
        }
        if (pos > 0 && pos <= n && s[pos - 1] == 'W' && sw < k && !vis[pos + 1])
        {
            if (pos + 1 == n + 1 || s[pos] != 'C')
            {
                vis[pos + 1] = true;
                q.push(make_pair(pos + 1, sw + 1));
            }
        }
    }

    return false;
}


void saurabh(){
    int n=1,m=0, k;
    string s;
    cin>>n>>m>>k;
    vi v(n);
    cin>>s;
    int ind = 0;
    if(cross(n,m,k, s)){
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
        saurabh();
    }
    return 0;
}

    