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


void saurabh(){
    int n=1, m= 0;
    cin>>n>>m;
    unordered_map<int, int> ump;
    vi v(n), q;
    cin>>v;
    srt(v);
    q.push_back(v[0]);

    ump[v[0]]++;

    rep(i, 1, n-1){
        ump[v[i]]++;
        if(v[i] != v[i-1]){
            q.push_back(v[i]);
        }
    }

    int res = 0, s = q.size();

    fr(i, s){
        if ((s > i + 1) && (q[i + 1] == q[i] + 1))
        {
            int dic = ump[q[i]];
            while(dic){
                int z = q[i]*dic;
                if(z > m){
                    int multi = m/q[i];
                    res = max(res, q[i]*multi);
                    dic--;
                    continue;
                }

                int glass = m - z;
                int multi = glass/q[i+1];
                if(multi > ump[q[i+1]]){
                   z+= q[i+1]*ump[q[i+1]];
                }else{
                    z+=q[i+1]*multi;
                }
                res = max(res, z);
                dic--;
            }
        }
        else
        {
            int o = m/q[i];
            int a = 0;
            if(o > ump[q[i]]){
                a=q[i]*ump[q[i]];
            }else{
                a=q[i]*o;
            }
            res = max(res, a);
        }
    }
    cout<<res;
    nl;
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

    