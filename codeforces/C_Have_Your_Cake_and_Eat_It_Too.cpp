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

int sumvec(vector<int> v)
{
    int n = v.size();
    int s = 0;
    fr(i, n) s += v[i];
    return s;
}

bool check(vector<int> v, int x, vvi &vp){
    int sum = 0, ind  = 0, l = 0;
    vector<pair<int, pair<int, int>>> ans;
    fr (i, vp[ind].size())
    {
        sum += vp[v[ind]][i];
        if (sum >= x)
        {
            ans.push_back({v[ind], {l, i}});
            ind++;
            sum = 0;
            l = i + 1;
            if (ind == 3)
                break;
        }
    }
    if (ind == 3)
    {
        sort(ans.begin(), ans.end());
        for (auto &it : ans)
        {
            cout << it.second.first + 1 << " " << it.second.second + 1 << " ";
        }
        cout << "\n";
        return true;
    }
    else
    {
        return false;
    }
}
void saurabh(){
    int n=1,m=0;
    string s;
    cin>>n;
    vvi vp(3);
    fr(i,3){
        vi v(n);
        cin>>v;
        vp[i] = v; 
    }
    int x = (sumvec(vp[1]) + 2) / 3;
    if (check({0, 1, 2}, x, vp))
        return;
    if (check({0, 2, 1}, x, vp))
        return;
    if (check({1, 0, 2}, x, vp))
        return;
    if (check({1, 2, 0}, x, vp))
        return;
    if (check({2, 1, 0}, x, vp))
        return;
    if (check({2, 0, 1}, x, vp))
        return;
    cout << "-1\n";
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

    