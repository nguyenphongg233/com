#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ce(x) cerr << #x << " = " << x << endl
#define len(x) x.size();

#define getbit(x,n) ((x >> n) & 1);
#define turnoff(x,n) (x & ~(1 << n));
#define turnon(x,n) (x | (1<<n))

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

//  code là cái gì ?

using namespace std;

ll base = 26,h[MAX],p[MAX];
string s;

ll gethash(ll l,ll r){
    return (h[r] - (h[l-1] * p[r - l + 1]) + mod * mod) % mod;
}


signed main(){
    faster();
    
    cin>>s;

    p[0] = 1;
    h[0] = 1;

    for(ll i = 1;i <= s.size();i++){
        p[i] = (p[i-1] * base) % mod;
        h[i] = (h[i-1] * base + s[i] - 'a' + 1) % mod;
    }

    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}