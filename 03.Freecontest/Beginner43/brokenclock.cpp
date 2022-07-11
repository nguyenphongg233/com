#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll n, kk = 1108;
string s, ans;

signed main(){
    
    
    cin >> n >> s;
    ll l = 1, r = 12;
    if(n == 24) l = 0, r = 23;
    for(int i = l; i <= r; i++){
        for(int j = 0; j < 60; j++){
            string res = ":";
            string a = to_string(i), b = to_string(j);
            if(a.size() == 1) a = '0' + a;
            if(b.size() == 1) b = '0' + b;
            res = a + res + b;
            ll gg = 0;
            for(ll k = 0; k < s.size(); k++){
                if(res[k] != s[k]) gg++;
            }
            if(gg < kk){
                kk = gg;
                ans = res;
            }
        }
    }
    cout << ans;
    
    return 0;
}