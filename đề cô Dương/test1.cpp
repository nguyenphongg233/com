#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FOD(i, a, b) for (ll i = a; i >= b; i--)

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 105;
const long long  INF = 361700864190383365;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n,m,a[MAX][MAX],dp[MAX][MAX],res = 0;

signed main(){
       faster();
       cin>>n>>m;
       FOR(i,1,n)FOR(j,1,m)cin>>a[i][j];
       FOR(i,1,n)dp[i][1] = a[i][1];
       FOR(j,2,m)FOR(i,1,n){
           if(i==1)dp[i][j] = max(a[i][j],dp[n][j-1] + a[i][j]);
           else {
               dp[i][j] = 0;
               FOR(z,1,i-1)dp[i][j] = max(dp[i][j],dp[z][j-1] + a[i][j]);
           }
           res = max(res,dp[i][j]);
       }
       FOR(i,1,n){
           FOR(j,1,m)cout<<dp[i][j]<<"\t";
           cout<<"\n";
       }
       cout<<res;
       return 0;
}