#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define matrix vector<vi>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;




signed main(){
    faster();
    ll d = 0;
    for(ll i = 0;i<=5;i++){
        for(ll j = 0; j <= 5 ; j++){
            for(ll z = 0 ; z<= 5 ;z++){
                if(i != 0 && i != j && i!= z && z!= j && (i + j + z) % 3 != 0)d++;
            }
        }
    }
    cout<<d;
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}