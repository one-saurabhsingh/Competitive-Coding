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

int func(const string& dis){
    cout<< "? " << dis;
    nl;
    int r = 0;
    cin>>r;
    return r;
}
void func2(string sac, int g){
    string res = "00";
    res = sac;
    int b = 0;
    string ah = "";
    string bf = "";
    fr(i,g-2){
        string c1 = res + "0";
        string c2 = res + "1";
        if(b == 0){
            if(func(c1)){
                res = c1;
            }
            else if (func(c2))
            {
                res = c2;
            }else{
                b = 1;
            }
        }
        if(b == 1){
            string cu1 = "0" + res;
            string cu2 = "1" + res;

            if(func(cu1)){
                res = cu1;
            }else{
                res = cu2;
            }
        }
        
    }
    cout<< "! "<< res;
    nl;
}
void saurabh(){
    int n=1,m=0;
    string s= "";
    cin>>n;
   // vi v(n);

//    int z = func("0");
//    int o = func("1");
//     if(z){
//         s[0] = '0';
//     }else{
//         s[0] = '1';
//     }
//     rep(k, 1, n){
//         string perf = s.substr(0, k);
//         if(func(perf + "0")){
//             s[k] = '0';
//         }else{
//             s[k] = '1';
//         }
//     }

//     cout<< "! "<< s;
//     nl;
//     cout.flush();
//     return;

    if(n == 1){
        if(func("1")){
            cout<<"! 1";
            nl;
        }else{
            cout<<"! 0";
            nl;
        }
        return;
    }

    if(func("00")){
        func2("00", n);
    }
    else if (func("01"))
    {
        func2("01", n);
    }
    else if (func("10"))
    {
        func2("10", n);
    }
    else{
        string r = "";
        fr(i,n){
            r+= "1";
        }
        cout<<"! "<<r;
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
        saurabh();
    }
    return 0;
}

    