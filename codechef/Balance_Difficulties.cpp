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
    int n=1,m=0;
    string s;
    cin>>n>>m;
    vi v(n);
    cin>>v;
    if(n == 1){
        cout<< "0";
        nl;
        cout<<v[0];
        nl;
        return;
    }
    int l = 0, h = 2e9, r = h;

    while(l <= h){
        int mid = (l+h)>>1;
        bool fk = true;
        int pl = v[0]-mid;
        int ph = v[0]+mid;

        rep(i, 1, n-1){
            int cl = max(v[i]-mid, pl);
            int ch = max(v[i]+mid, ph+m);

            if(cl > ch){
                fk = false;
                break;
            }
            pl = cl;
            ph = ch;
        }
        if(fk){
            r = mid;
            h = mid-1;
        }else{
            l = mid+1;
        }
    }

    vector<pair<int,int>> boo(n);
    boo[0] = {v[0] - r, v[0]+r};

    rep(i, 1, n-1){
        int nal = max(v[i]-r, boo[i-1].first);
        int nh = min(v[i]+r, boo[i-1].second+m);
        boo[i] = {nal, nh};
    }

    vi car(n);

    car[n-1] = boo[n-1].second;
    for(int i = n-2; i>= 0; i--){
        car[i] = min(boo[i].second, car[i+1]);
        car[i] = max(car[i], boo[i].first);
    }

    int kfu = 0;
    fr(i, n){
        int pq = abs(car[i] - v[i]);
        if(pq > kfu){
            kfu = pq;
        }
    }

    cout<< kfu;
    nl;
    fr(i, n){
        cout<< car[i]<<" ";
    }
    nl;
    return;

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

    